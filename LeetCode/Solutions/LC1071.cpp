/*
Problem Statement: https://leetcode.com/problems/greatest-common-divisor-of-strings/
*/

class Solution {
public:
	string gcdOfStrings(string& str1, string& str2) {
		int g = gcd(str1.length(), str2.length());
		return (str1 + str2 == str2 + str1) ? str1.substr(0, g) : "";
	}
};