/*
Problem Statement: https://leetcode.com/problems/jewels-and-stones/
Time: O(J + S)
Space: O(J)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int numJewelsInStones(string J, string S) {
		int cnt = 0;
		unordered_set<char> jewels(J.begin(), J.end());
		for (char& c: S)
			if (jewels.count(c))
				cnt++;
		return cnt;
	}
};