/*
Problem Statement: https://leetcode.com/problems/valid-number/
*/

class Solution {
public:
    bool isNumber(string& s) {
        regex pattern("^\\s*[+-]?(\\d+(\\.\\d*)?|\\.\\d+)(e[+-]?\\d+)?\\s*$");
		return regex_match(s, pattern);
    }
};