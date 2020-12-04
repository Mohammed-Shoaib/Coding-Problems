/*
Problem Statement: https://leetcode.com/problems/add-strings/
*/

class Solution {
public:
	string addStrings(string num1, string num2) {
		string s;
		int sum, carry, i, j;
		
		carry = 0;
		i = num1.length() - 1;
		j = num2.length() - 1;

		while (i >= 0 || j >= 0 || carry) {
			sum = carry;
			if (i >= 0)
				sum += (num1[i--] - '0');
			if (j >= 0)
				sum += (num2[j--] - '0');
			s += (sum % 10) + '0';
			carry = sum / 10;
		}
		reverse(s.begin(), s.end());
		
		return s;
	}
};