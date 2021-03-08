#pragma once
#include <vector>

using namespace std;

/*
Description about class parameters
lock - a mutex lock to avoid duplicate writing
idx  - the assigned ID of this car
pos  - the position of the car in path
path - an array of street ID's representing the path of the car
*/

struct Car {
	bool lock;
	int idx, pos, eta;
	vector<int> path;
	
	int get_street();
	int get_intersection();
	bool is_first();
	bool can_go(int t);
	bool has_arrived();
	void move(int t);
};