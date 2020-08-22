/*
Problem Statement: https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/
*/

class Solution {
public:
	int maxLength(vector<string>& arr) {
		int max_length = 0;
		const int n = 26;
		vector< bitset<n> > dp = {bitset<n>()};
		
		for (int i = 0; i < arr.size(); i++) {
			bitset<n> curr;
			for (char c: arr[i])
				curr.set(c - 'a');
			if (curr.count() < arr[i].length())
				continue;
			for (int j = dp.size() - 1; j >= 0; j--) {
				bitset used = dp[j];
				if ((used & curr).any())
					continue;
				used |= curr;
				max_length = max((int)used.count(), max_length);
				dp.push_back(used);
			}
		}
		
		return max_length;
	}
};