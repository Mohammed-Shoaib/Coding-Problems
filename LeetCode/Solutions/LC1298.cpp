/*
Problem Statement: https://leetcode.com/problems/maximum-candies-you-can-get-from-boxes/
*/

class Solution {
public:

	int maxCandies(vector<int>& status, vector<int>& candies, vector< vector<int> >& keys, vector< vector<int> >& containedBoxes, vector<int>& initialBoxes) {
		int candy, n, box;
		candy = 0;
		n = status.size();
		queue<int> q;
		vector<bool> reach(n), visited(n);

		// Helper function to process box
		auto process = [&](int box) {
			if (!visited[box] && status[box] && reach[box]) {
				q.push(box);
				visited[box] = true;
			}
		};

		// Initialize queue
		for (int box: initialBoxes) {
			reach[box] = true;
			process(box);
		}

		// Go through all boxes possible
		while (!q.empty()) {
			box = q.front();
			q.pop();
			candy += candies[box];

			// Go through keys found and unlock
			for (int b: keys[box]) {
				status[b] = 1;
				process(b);
			}

			// Go through boxes found and mark them reachable
			for (int b: containedBoxes[box]) {
				reach[b] = true;
				process(b);
			}
		}

		return candy;
	}
};