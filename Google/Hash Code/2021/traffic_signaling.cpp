#include <iostream>
#include <cstdio>
#include <cmath>
#include <cassert>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <algorithm>
#include "Car.h"
#include "Street.h"
#include "Intersection.h"

using namespace std;

/*
Description about the parameters
D - the duration of the simulation
I - the number of intersections
S - the number of streets
V - the number of cars
F - the bonus points for each car that reaches its destination before time D

Description about the streets
B - the intersection at the start of the street
E - the intersection at the end of the street
R - the street or road name
L - the time it takes a car to get from the beginning to the end of that street

Description about the cars
P - the number of streets that the car wants to travel
W - an array representing the path or walk of the car in order

Description about the output
A - the number of intersections for which a schedule is specified
E – the number of incoming streets (of the intersection i) covered by this schedule
T – for how long each street will have a green light
*/

// global variables
int D, I, S, V, F;
unordered_map<string, int> mp_R;
Car cars[1000];
Street streets[100000];
Intersection intersections[100000];

// returns the street index of car
int Car::get_street() {
	assert(pos < static_cast<int>(path.size()));
	return path[pos];
}

// returns the intersection index of car
int Car::get_intersection() {
	return streets[get_street()].end;
}

// checks if car is first in queue
bool Car::is_first() {
	assert(!streets[get_street()].q.empty());
	int v_idx = streets[get_street()].q.front();
	return v_idx == idx;
}

// checks if car is ready to go at time = t seconds
bool Car::can_go(int t) {
	return !has_arrived() && eta <= t && is_first() && streets[get_street()].is_green(t);
}

// checks if car has arrived its destination
bool Car::has_arrived() {
	return pos + 1 == static_cast<int>(path.size()) && eta <= D;
}

// moves this car if it can go
void Car::move(int t) {
	// remove car from end of queue
	streets[get_street()].q.pop();
	streets[get_street()].lock = true;
	
	// lock car to unlock street
	lock = true;
	
	// update car parameters to next street
	pos++;
	Street& street = streets[get_street()];
	eta = t + street.len;
	
	// avoid queuing at the last intersection
	if (pos + 1 < static_cast<int>(path.size())) {
		street.used = true;
		street.q.push(idx);
		street.max_q_size = max(static_cast<int>(street.q.size()), street.max_q_size);
	}
}

// initializes all the signals to be red
Street::Street(): dur(0) {}

// checks if signal is green at time = t seconds for this street
bool Street::is_green(int t) {
	int mod = intersections[end].dur_len;
	assert(mod > 0);
	t %= mod;
	return !lock && range.first <= t && t < range.second;
}

// updates the range the signal is green from time = t seconds for the duration
void Street::update_range(int t) {
	range = {t, t + dur};
}

// uniformly assigns all the signals to be green for dur seconds
void Intersection::uniform(int dur) {
	order_deg = dur_len = in_deg;
	for (int s = 0; s < in_deg; s++) {
		int s_idx = in_adj[s];
		order[s] = s_idx;
		mp_order[s_idx] = s;
		streets[s_idx].dur = dur;
		streets[s_idx].update_range(s);
	}
}

// updates the range a signal is open for all streets
void Intersection::update_ranges() {
	int total = 0;
	for (int& s_idx: order) {
		if (s_idx == -1)
			continue;
		streets[s_idx].update_range(total);
		total += streets[s_idx].dur;
	}
	dur_len = total;
}

// uses earliest deadline first to get an ordering for signals
void Intersection::round_robin(int t, int s_idx) {
	int mod = order.size();
	assert(mod > 0);
	t %= mod;
	
	// street has been processed already
	if (mp_order.count(s_idx) || static_cast<int>(mp_order.size()) == mod)
		return;
	
	// find a position greedily
	int start = t;
	while (order[t] != -1) {
		t = (t + 1) % mod;
		assert(start != t);
	}
	
	// add street to intersection ordering
	order_deg++;
	order[t] = s_idx;
	mp_order[s_idx] = t;
	
	// set the time duration for street
	streets[s_idx].dur = 1;
	streets[s_idx].update_range(t);
}

// processes the input based on the format
void process_input() {
	cin >> D >> I >> S >> V >> F;
	
	// process streets
	for (int s = 0; s < S; s++) {
		cin >> streets[s].beg >> streets[s].end >> streets[s].name >> streets[s].len;
		streets[s].idx = s;
		mp_R[streets[s].name] = s;
	}
	
	// process cars
	for (int v = 0; v < V; v++) {
		int P;
		cin >> P;
		cars[v].idx = v;
		
		while (P--) {
			string street;
			cin >> street;
			cars[v].path.push_back(mp_R[street]);
		}
	}
	
	// create adjacency graph
	for (int s = 0; s < S; s++) {
		intersections[streets[s].end].in_adj.push_back(s);
		intersections[streets[s].beg].out_adj.push_back(s);
	}
	
	// process intersections
	for (int i = 0; i < I; i++) {
		intersections[i].idx = i;
		intersections[i].in_deg = intersections[i].in_adj.size();
	}
}

// process the output based on the format
void process_output() {
	// count valid intersections
	int A = 0;
	for (int i = 0; i < I; i++) {
		intersections[i].block = intersections[i].order_deg == 0;
		A += !intersections[i].block;
	}
	cout << A << endl;
	
	// output the solution for valid intersections
	for (int i = 0; i < I; i++) {
		if (intersections[i].block)
			continue;
		
		cout << i << endl;
		cout << intersections[i].order_deg << endl;
		
		for (int& s_idx: intersections[i].order)
			if (s_idx != -1)
				cout << streets[s_idx].name << " " << streets[s_idx].dur << endl;
	}
}

// resets values that are not persistent to its initial state
void reset_signaling(bool round_robin = false) {
	// reset all the streets
	for (int s = 0; s < S; s++) {
		streets[s].used = false;
		streets[s].max_q_size = 0;
		streets[s].range = {0, 0};
	}
	
	// remove cars from queue of streets
	for (int v = 0; v < V; v++) {
		int s_idx = cars[v].get_street();
		while (!streets[s_idx].q.empty())
			streets[s_idx].q.pop();
	}
	
	// reset the state of all cars
	for (int v = 0; v < V; v++) {
		cars[v].pos = cars[v].eta = 0;
		streets[cars[v].path[0]].q.push(v);
		streets[cars[v].path[0]].used = true;
		streets[cars[v].path[0]].max_q_size++;
	}
	
	// reset the state of all intersections
	for (int i = 0; i < I; i++) {
		if (round_robin)
			continue;
		intersections[i].mp_order.clear();
		intersections[i].order_deg = 0;
		intersections[i].dur_len = intersections[i].in_deg;
		intersections[i].order.assign(intersections[i].in_deg, -1);
	}
}

// simulate the entire process of signaling
int simulate_signaling(bool round_robin = false) {
	unordered_set<int> seen_intersection;
	
	// run the simulation
	for (int t = 0; t < D; t++) {
		// move cars that can go
		for (int v = 0; v < V; v++) {
			if (cars[v].pos + 1 == static_cast<int>(cars[v].path.size()))
				continue;
			int i_idx, s_idx;
			i_idx = cars[v].get_intersection();
			s_idx = cars[v].get_street();
			if (cars[v].is_first()) {
				seen_intersection.insert(i_idx);
				intersections[i_idx].round_robin(cars[v].eta, s_idx);
			}
			if (cars[v].can_go(t))
				cars[v].move(t);
		}
		
		// reset the locks
		for (int v = 0; v < V; v++)
			if (cars[v].lock) {
				int s_idx = cars[v].path[cars[v].pos - 1];
				cars[v].lock = false;
				streets[s_idx].lock = false;
			}
	}
	
	// compute score
	int score = 0;
	for (int v = 0; v < V; v++)
		if (cars[v].has_arrived()) {
			int bonus = D - cars[v].eta;
			score += F + bonus;
		}
	cerr << score << endl;
	
	// only run the simulation
	if (!round_robin)
		return score;
	
	// reset order until an ordering is found
	for (auto& i: seen_intersection) {
		intersections[i].mp_order.clear();
		intersections[i].dur_len = intersections[i].order_deg;
		intersections[i].order.assign(intersections[i].order_deg, -1);
		intersections[i].order_deg = 0;		
	}
	reset_signaling(true);
	
	return score;
}

// uniformly assigns all the signals at each intersection to be green for dur seconds
void uniform_signaling() {
	int dur = 1;
	for (int i = 0; i < I; i++)
		intersections[i].uniform(dur);
}

// runs simulation to get a valid ordering using EDF scheduling
void traffic_signaling() {
	process_input();
	reset_signaling();
	simulate_signaling(true);
	simulate_signaling();
	process_output();
}

int main(int argc, char **argv) {
	// fast input & output
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	// file input & output
	string f = argv[1];
	freopen(("input/" + f + ".in").c_str(), "r", stdin);
	freopen(("output/" + f + ".out").c_str(), "w", stdout);
	
	traffic_signaling();
	
	return 0;
}