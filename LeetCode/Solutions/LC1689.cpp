/*
Problem Statement: https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int minPartitions(string n) {
		return *max_element(n.begin(), n.end()) - '0';
	}
};