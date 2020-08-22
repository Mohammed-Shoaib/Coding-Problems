/*
Problem Statement: https://www.hackerrank.com/challenges/common-child/problem
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int commonChild(string &s1, string &s2) {
	int n = s1.length();
	vector<int> prev(n + 1), curr(n + 1);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (s1[i - 1] == s2[j - 1])
				curr[j] = prev[j - 1] + 1;
			else
				curr[j] = max(prev[j], curr[j - 1]);
		}
		prev = curr;
	}
	
	return curr[n];
}

int main() {
	string s1, s2;
	cin >> s1 >> s2;
	cout << commonChild(s1, s2);
	return 0;
}