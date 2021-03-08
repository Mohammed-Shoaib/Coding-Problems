#pragma once
#include <string>
#include <queue>
#include <utility>

using namespace std;

/*
Description about class parameters
used       - a boolean to represent whether this street is being used
lock       - a mutex lock to avoid duplicate writing
idx        - the assigned ID of this street
beg        - the ID of the intersection at the beginning of this street
end        - the ID of the intersection at the end of this street
len        - the total distance or length of this street
dur        - the duration for which the signal is green
max_q_size - the maximum number of cars at any given point to represent traffic
name       - the assigned name of this street
q          - a queue representing one-dimensional traffic
range      - a time range for which the signal is green, includes the begin
             time but excludes the end time
*/

struct Street {
	bool used, lock;
	int idx, beg, end, len, dur, max_q_size;
	string name;
	queue<int> q;
	pair<int, int> range;
	
	Street();
	bool is_green(int t);
	void update_range(int t);
};