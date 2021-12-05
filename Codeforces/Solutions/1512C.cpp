/*
Problem Code: 1512C
Time: O(n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool is_palindrome(int n, string& s) {
	return equal(s.begin(), s.begin() + n / 2, s.rbegin());
}

string ab_palindrome(int a, int b, string& s) {
	int n = s.length();
	
	for (int i = 0; i < n; i++)
		if (s[i] == '?')
			s[i] = s[n - i - 1];
	
	a -= count(s.begin(), s.end(), '0');
	b -= count(s.begin(), s.end(), '1');
	
	if ((n & 1) && s[n / 2] == '?') {
		if (a & 1)
			a--, s[n / 2] = '0';
		else
			b--, s[n / 2] = '1';
	}
	
	for (int i = 0; i < n / 2; i++) {
		if (s[i] == '?') {
			if (a) {
				a -= 2;
				s[i] = s[n - i - 1] = '0';
			} else {
				b -= 2;
				s[i] = s[n - i - 1] = '1';
			}
		}
	}
	
	if (a || b || !is_palindrome(n, s))
		return "-1";
	else
		return s;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int a, b;
		string s;
		cin >> a >> b >> s;
		cout << ab_palindrome(a, b, s) << endl;
	}
	return 0;
}