/*
Problem Code: https://www.hackerrank.com/challenges/sherlock-and-valid-string/problem
*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int most_common(unordered_map<char, int> &freq) {
	int max_freq, max_cnt = 0;
	unordered_map<int, int> count;

	for (auto it: freq)
		count[it.second]++;

	for (auto it: count)
		if (it.second > max_cnt) {
			max_cnt = it.second;
			max_freq = it.first;
		}

	return max_freq;
}

string isValid(string &s) {
	unordered_map<char, int> freq;
	
	for (char c: s)
		freq[c]++;

	bool flag = false;
	int max_freq = most_common(freq);

	for (auto it: freq) {
		if (it.second == max_freq)
			continue;
		else if (!flag && (max_freq != 1 && it.second == 1 || it.second - 1 == max_freq))
			flag = true;
		else
			return "NO";
	}

	return "YES";
}

int main() {
	string s;
	cin >> s;
	cout << isValid(s);
	return 0;
}