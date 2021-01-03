/*
Problem Statement: https://leetcode.com/problems/maximum-number-of-balloons/
*/

class Solution {
public:
	int maxNumberOfBalloons(string text) {
		int cnt;
		unordered_map<char, int> freq;

		for (char c: text)
			freq[c]++;

		cnt = min(freq['b'], freq['a']);
		cnt = min(cnt, freq['l'] / 2);
		cnt = min(cnt, freq['o'] / 2);
		cnt = min(cnt, freq['n']);

		return cnt;
	}
};