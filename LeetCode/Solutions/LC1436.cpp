/*
Problem Statement: https://leetcode.com/problems/destination-city/
Time: O(n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	string destCity(vector<vector<string>>& paths) {
		string city;
		unordered_set<string> src, dst;
		
		for (auto& e: paths) {
			src.insert(e[0]);
			dst.insert(e[1]);
		}
		
		for (auto& s: dst)
			if (!src.count(s)) {
				city = s;
				break;
			}
		
		return city;
	}
};