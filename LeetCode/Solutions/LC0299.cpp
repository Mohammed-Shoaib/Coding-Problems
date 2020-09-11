/*
Problem Statement: https://leetcode.com/problems/bulls-and-cows/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	string getHint(string secret, string guess) {
		int a, b, n;
		n = secret.length();
		a = b = 0;
		vector<int> cnt_a(10), cnt_b(10);
		
		for (int i = 0; i < n; i++) {
			if (secret[i] == guess[i])
				a++;
			else {
				cnt_a[secret[i] - '0']++;
				cnt_b[guess[i] - '0']++;
			}
		}
		
		for (int i = 0; i < 10; i++)
			b += min(cnt_a[i], cnt_b[i]);
		
		return to_string(a) + "A" + to_string(b) + "B";
	}
};