/*
Problem Statement: https://www.hackerrank.com/challenges/palindrome-index/problem
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool isPalindrome(string s) {
	return equal(s.begin(), s.begin() + s.length() / 2, s.rbegin());
}

int palindromeIndex(string s) {
	int i, j;
	string s1, s2;

	if (isPalindrome(s))
		return -1;

	for (i = 0, j = s.length() - 1; i < s.length() / 2; i++, j--)
		if (s[i] != s[j]) {
			s1 = s.substr(0, i) + s.substr(i + 1);
			s2 = s.substr(0, j) + s.substr(j + 1);
			break;
		}
	
	if (isPalindrome(s1))
		return i;
	else if (isPalindrome(s2))
		return j;
	else
		return -1;
}

int main() {
	int q;
	cin >> q;
	while (q--) {
		string s;
		cin >> s;
		cout << palindromeIndex(s) << endl;
	}
	return 0;
}