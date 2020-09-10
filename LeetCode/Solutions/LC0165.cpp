/*
Problem Statement: https://leetcode.com/problems/compare-version-numbers/
Time: O(m + n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int compareVersion(string version1, string version2) {
		int m = version1.length(), n = version2.length();
		for (int i = 0, j = 0; i < m || j < n; i++, j++) {
			int v1, v2;
			v1 = v2 = 0;
			while (i < m && version1[i] != '.')
				v1 = 10 * v1 + version1[i++] - '0';
			while (j < n && version2[j] != '.')
				v2 = 10 * v2 + version2[j++] - '0';
			if (v1 < v2)
				return -1;
			else if (v1 > v2)
				return 1;
		}
		return 0;
	}
};