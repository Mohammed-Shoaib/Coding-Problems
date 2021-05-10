/*
Problem Statement: https://leetcode.com/problems/super-palindromes/
Time: O(limit • log limit) = O(50'000 • log 50'000)
Space: O(log limit) = O(log 50'000)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
private:
	bool is_palindrome(int64_t num) {
		string s = to_string(num);
		int n = s.length();
		return equal(s.begin(), s.begin() + n / 2, s.rbegin());
	}
	
public:
	int superpalindromesInRange(string left, string right) {
		int cnt = 0, limit = 50'000;
		int64_t l = stoll(left), r = stoll(right);
		
		for (int64_t i = 1; i <= limit; i++) {
			string s, t;
			s = t = to_string(i);
			reverse(t.begin(), t.end());
			int64_t x = stoll(s + t.substr(1));
			if (x <= 1e9 && x * x >= l && x * x <= r && is_palindrome(x) && is_palindrome(x * x))
				cnt++;
			x = stoll(s + t);
			if (x <= 1e9 && x * x >= l && x * x <= r && is_palindrome(x) && is_palindrome(x * x))
				cnt++;
		}
		
		return cnt;
	}
};