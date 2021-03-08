#pragma once
#include <vector>
#include <utility>
#include <unordered_map>

using namespace std;

/*
Description about class parameters
block     - a boolean representing whether this street should be blocked
idx       - the assigned ID of this intersection
dur_len   - the time duration of this intersection, is equivalent to sum of
            durations for each street
in_deg    - the number of incoming streets
order_deg - the number of streets used in order
mp_order  - maps the street ID to its position in the order array
in_adj    - an array of street ID's representing the incoming streets
out_adj   - an array of street ID's representing the outgoing streets
order     - an array which is -1 if a position is not taken, else the street ID
            of the street taking the position
*/

struct Intersection {
	bool block;
	int idx, dur_len, in_deg, order_deg;
	unordered_map<int, int> mp_order;
	vector<int> in_adj, out_adj, order;
	
	void update_ranges();
	void uniform(int dur);
	void round_robin(int t, int s_idx);
};