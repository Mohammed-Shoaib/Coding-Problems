/*
Problem Statement: https://leetcode.com/problems/counting-elements/
*/

class Solution {
public:
	int countElements(vector<int>& arr) {
		int cnt = 0;
		unordered_map<int, int> freq;
		for (int a: arr)
				freq[a]++;
		for (auto& [k, v]: freq)
			if (freq.count(k + 1))
				cnt += v;
		return cnt;
	}
};