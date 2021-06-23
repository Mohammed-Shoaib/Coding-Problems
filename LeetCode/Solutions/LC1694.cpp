/*
Problem Statement: https://leetcode.com/problems/reformat-phone-number/
Time: O(n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	string reformatNumber(string number) {
		string t;
		int cnt = 0;
		
		for (char& c: number) {
			if (!isdigit(c))
				continue;
			else if (cnt && cnt % 3 == 0)
				t += '-';
			cnt++;
			t += c;
		}
		
		if (cnt % 3 == 1)
			iter_swap(t.end() - 3, t.end() - 2);
		
		return t;
	}
};