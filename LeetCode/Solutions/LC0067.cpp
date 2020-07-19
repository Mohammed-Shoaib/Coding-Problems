/*
Problem Statement: https://leetcode.com/problems/add-binary/
Time: O(n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
    string addBinary(string a, string b) {
		string c;
		int sum, carry, i, j;
		carry = 0;
		i = a.length() - 1;
		j = b.length() - 1;

		while (i >= 0 || j >= 0 || carry) {
			sum = carry;
			if (i >= 0)
				sum += (a[i--] - '0');
			if (j >= 0)
				sum += (b[j--] - '0');
			c += (sum & 1) + '0';
			carry = sum >> 1;
		}
		reverse(c.begin(), c.end());

		return c;
    }
};