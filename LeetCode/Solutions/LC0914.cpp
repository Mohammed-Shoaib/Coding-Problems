/*
Problem Statement: https://leetcode.com/problems/x-of-a-kind-in-a-deck-of-cards/
*/

class Solution {
public:
	bool hasGroupsSizeX(vector<int>& deck) {
		unordered_map<int, int> freq;
		for (int& card: deck)
			freq[card]++;
		int g = accumulate(freq.begin(), freq.end(), 0, [](int res, auto it) { return gcd(it.second, res); });
		return g >= 2;
	}
};