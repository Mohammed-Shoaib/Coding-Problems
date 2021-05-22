/*
Problem Statement: https://leetcode.com/problems/ambiguous-coordinates/
Time: O(n⁴)
Space: O(n⁴)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	vector<string> ambiguousCoordinates(string s) {
		int n = s.length();
		vector<string> coords;
		
		// helper function to generate decimal numbers
		auto generate = [&](string t) {
			vector<string> nums;
			
			if (t.empty())
				return nums;
			else if (t.length() == 1 || t[0] != '0')
				nums.push_back(t);
			
			for (int i = 1; i < t.length() && t.back() != '0'; i++) {
				nums.push_back(t.substr(0, i) + "." + t.substr(i));
				if (t[0] == '0')
					break;
			}
			
			return nums;
		};
		
		// split string with comma
		for (int i = 1; i + 1 < n; i++) {
			vector<string> cand_l, cand_r;
			cand_l = generate(s.substr(1, i));
			cand_r = generate(s.substr(i + 1, n - i - 2));
			
			// cartesian product
			for (string& l: cand_l)
				for (string& r: cand_r)
					coords.push_back("(" + l + ", " + r + ")");
		}
		
		return coords;
	}
};