/*
Problem Statement: https://www.hackerrank.com/challenges/queens-attack-2/problem
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <utility>
#include <numeric>
#include <algorithm>

using namespace std;

int get_distance(pair<int, int> p1, pair<int, int> p2) {
	int x = abs(p1.second - p2.second);
	int y = abs(p1.first - p2.first);
	return x ? (x - 1) : (y - 1);
}

int queensAttack(int n, int k, pair<int, int> q, vector< pair<int, int> > &obs) {
	int qx, qy, obx, oby, diffx, diffy, dist;
	qx = q.second;
	qy = q.first;
	vector<int> dir = { n - qy, 				// North
						qy - 1, 				// South
						n - qx, 				// East
						qx - 1, 				// West
						min(n - qx, n - qy),	// North-East
						min(n - qx, qy - 1),	// South-East
						min(qx - 1, n - qy),	// North-West
						min(qx - 1, qy - 1) };	// South-West
	
	for (int i = 0; i < k; i++) {
		obx = obs[i].second;
		oby = obs[i].first;
		diffx = obx - qx;
		diffy = oby - qy;
		dist = get_distance(q, obs[i]);

		if (qx == obx) {
			// North
			if (qy < oby)
				dir[0] = min(dist, dir[0]);
			
			// South
			else if(qy > oby)
				dir[1] = min(dist, dir[1]);
		} else if (qy == oby) {
			// East
			if (qx < obx)
				dir[2] = min(dist, dir[2]);

			// West
			else if (qx > obx)
				dir[3] = min(dist, dir[3]);
		} else if (abs(diffx) == abs(diffy)) {
			// North-East
			if(diffx > 0 && diffy > 0)
				dir[4] = min(dist, dir[4]);

			// South-East
			else if (diffx > 0 && diffy < 0)
				dir[5] = min(dist, dir[5]);

			// North-West
			else if (diffx < 0 && diffy > 0)
				dir[6] = min(dist, dir[6]);

			// South-West
			else if (diffx < 0 && diffy < 0)
				dir[7] = min(dist, dir[7]);
		}
	}

	return accumulate(dir.begin(), dir.end(), 0);
}

int main() {
	int n, k;
	cin >> n >> k;
	pair<int, int> q;
	vector< pair<int, int> > obs(k);
	cin >> q.first >> q.second;
	for (int i = 0; i < k; i++)
		cin >> obs[i].first >> obs[i].second;
	cout << queensAttack(n, k, q, obs);
	return 0;
}