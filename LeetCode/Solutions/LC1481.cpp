/*
Problem Statement: https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/
*/

class Solution {
public:
	int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
		int rem, n = arr.size();
		vector<int> uniq, cnt(n + 1);
		unordered_map<int, int> freq;

		for (int& x: arr)
			freq[x]++;
		for (auto& [k, v]: freq) {
			cnt[v]++;
			uniq.push_back(v);
		}
		
		rem = uniq.size();
		for (int i = 1; i <= n && k; i++) {
			rem -= min(cnt[i], k / i);
			k = max(0, k - i * cnt[i]);
		}
		
		return rem;
	}
};