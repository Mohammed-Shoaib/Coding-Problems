/*
Problem Statement: https://leetcode.com/problems/open-the-lock/
Time: O(slots ^ wheels + deadends)
Space: O(slots ^ wheels)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int openLock(vector<string>& deadends, string target) {
		int slots = 10, wheels = target.length();
		queue<int> q;
		vector<bool> visited(pow(slots, wheels));
		
		// helper function
		auto get_neighbors = [&](string& lock) {
			vector<int> neighbors;
			
			for (int i = 0; i < wheels; i++) {
				string next = lock;
				for (int j: {-1, 1}) {
					next[i] = (lock[i] + j + slots - '0') % slots + '0';
					neighbors.push_back(stoi(next));
				}
			}
			
			return neighbors;
		};
		
		// initialization
		for (string& x: deadends)
			visited[stoi(x)] = true;
		if (!visited[0])
			q.push(0);
		
		// BFS
		int level = 0;
		while (!q.empty()) {
			int size = q.size();
			while (size--) {
				string lock = to_string(q.front());
				lock = string(wheels - lock.length(), '0') + lock;
				q.pop();
				
				if (lock == target)
					return level;
				
				for (int& u: get_neighbors(lock))
					if (!visited[u]) {
						q.push(u);
						visited[u] = true;
					}
			}
			level++;
		}
		
		return -1;
	}
};