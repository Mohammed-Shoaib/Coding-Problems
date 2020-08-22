/*
Problem Statement: https://www.hackerrank.com/challenges/sherlock-and-anagrams/problem
*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

int sherlockAndAnagrams(string &s) {
	int sum = 0;
	string sub_s;
	unordered_map<string, int> freq;
	
	// Get all possible substrings
	for (int i = 0; i < s.length(); i++)
		for (int j = i + 1; j <= s.length(); j++) {
			// Count anagrammatic substring
			sub_s = string(s.begin() + i, s.begin() + j);
			sort(sub_s.begin(), sub_s.end());
			freq[sub_s]++;
		}
	
	// Sum all combinations of pairs
	for (auto f: freq)
		sum += (f.second * (f.second - 1)) / 2;
	
	return sum;
}

int main() {
	int q;
	cin >> q;
	while (q--) {
		string s;
		cin >> s;
		cout << sherlockAndAnagrams(s) << endl;
	}
}