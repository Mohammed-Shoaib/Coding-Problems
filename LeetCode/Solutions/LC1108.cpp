/*
Problem Statement: https://leetcode.com/problems/defanging-an-ip-address/
*/

class Solution {
public:
	string defangIPaddr(string address) {
		regex pattern("\\.");
		return regex_replace(address, pattern, "[.]");
	}
};