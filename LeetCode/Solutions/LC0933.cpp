/*
Problem Statement: https://leetcode.com/problems/number-of-recent-calls/
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib

|-----------------|------|-------|
| Operations      | Time | Space |
|-----------------|------|-------|
| RecentCounter() | O(1) | O(1)  |
| ping()          | O(n) | O(1)  |
|-----------------|------|-------|
*/

class RecentCounter {
private:
	int range;
	queue<int> q;
public:
	RecentCounter() : range(3000) {}
	
	int ping(int t) {
		q.push(t);
		while (q.front() < t - range)
			q.pop();
		return q.size();
	}
};