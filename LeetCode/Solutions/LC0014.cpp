/*
Problem Statement: https://leetcode.com/problems/longest-common-prefix/
*/

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		string prefix;
		if (strs.empty())
			return prefix;
		for (int j = 0; j < strs[0].length(); j++) {
			for (int i = 0; i < strs.size(); i++)
				if (j == strs[i].size() || strs[0][j] != strs[i][j])
					return prefix;
			prefix += strs[0][j];
		}
		return prefix;
	}
};