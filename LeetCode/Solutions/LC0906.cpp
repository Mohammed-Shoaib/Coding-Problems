/*
Problem Statement: https://leetcode.com/problems/super-palindromes/
Time: O(limit • log limit) = O(50'000 • log 50'000)
Space: O(log limit) = O(log 50'000)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
private:
	int64_t reverse(int64_t num) {
		int64_t rev = 0;
		while (num) {
			rev = 10 * rev + num % 10;
			num /= 10;
		}
		return rev;
	}
	
	int64_t generate_palindrome(int64_t prefix, int64_t suffix) {
		while (suffix) {
			prefix = 10 * prefix + suffix % 10;
			suffix /= 10;
		}
		return prefix;
	}
	
public:
	int superpalindromesInRange(string left, string right) {
		int64_t num, l, r;
		int cnt = 0, limit = 50'000;
		l = sqrt(stoll(left));
		r = sqrt(stoll(right));
		
		// helper functions
		auto is_super_palindrome = [&](int64_t num) {
			if (num < l || num > r)
				return false;
			num *= num;
			return num == reverse(num);
		};
		
		// even length palindromes
		for (int i = 1; i <= limit; i++) {
			int64_t num = generate_palindrome(i, i);
			if (num > r)
				break;
			cnt += is_super_palindrome(num);
		}
		
		// odd length palindromes
		for (int i = 1; i <= limit; i++) {
			num = generate_palindrome(i, i / 10);
			if (num > r)
				break;
			cnt += is_super_palindrome(num);
		}
		
		return cnt;
	}
};