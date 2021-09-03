/*
Problem Statement: https://leetcode.com/problems/reduce-array-size-to-the-half/
Time: O(n • log n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int minSetSize(vector<int>& arr) {
		int cnt, used, n = arr.size();
		priority_queue<int> pq;
		unordered_map<int, int> freq;
		
		for (int& x: arr)
			freq[x]++;
		
		for (auto& [key, val]: freq)
			pq.push(val);
		
		for (cnt = 0, used = 0; 2 * used < n; cnt++) {
			used += pq.top();
			pq.pop();
		}
		
		return cnt;
	}
};