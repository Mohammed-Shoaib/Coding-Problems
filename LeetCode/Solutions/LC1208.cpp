/*
Problem Statement: https://leetcode.com/problems/get-equal-substrings-within-budget/
*/

class Solution {
public:
    int equalSubstring(string& s, string& t, int maxCost) {
    	int length, cost;
    	length = cost = 0;
    	
		for (int i = 0, j = 0; i < s.length(); i++) {
    		cost += abs(s[i] - t[i]);
    		
			while(cost > maxCost) {
    			cost -= abs(s[j] - t[j]);
				j++;
			}
    		
			length = max(i - j + 1, length);
    	}
    	
		return length;
    }
};