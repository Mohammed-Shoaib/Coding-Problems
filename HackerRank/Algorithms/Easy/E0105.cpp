/*
Problem Statement: https://www.hackerrank.com/challenges/two-characters/problem
*/

#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int alternate(string &s) {
	int len = 0, n = 26;
	vector< vector<int> > cnt(n, vector<int>(n));
	vector< vector< pair<char, char> > > comb(n, vector< pair<char, char> >(n));
	
	// Initialization
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			comb[i][j] = make_pair('a' + i, 'a' + j);
			if (i == j)
				cnt[i][j] = -1;
		}
	
	// Check for each combination in string
	for (int k = 0; k < s.length(); k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				if (cnt[i][j] == -1)
					continue;
				else if (s[k] == comb[i][j].first) {
					swap(comb[i][j].first, comb[i][j].second);
					cnt[i][j]++;
				}
				else if(s[k] == comb[i][j].second)
					cnt[i][j] = -1;
			}
	
	// Calculate max length
	for (int i = 0; i < n; i++)
		len = max(len, *max_element(cnt[i].begin(), cnt[i].end()));
	
	if (len == 1)
		len = 0;
	
	return len;
}

int main() {
	int n;
	string s;
	cin >> n >> s;
	cout << alternate(s);
	return 0;
}