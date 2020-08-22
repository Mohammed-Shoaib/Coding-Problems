/*
Problem Statement: https://www.hackerrank.com/challenges/game-of-thrones/problem
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string gameOfThrones(string s) {
	int count, letters;
	count = 0;
	letters = 26;
	vector<int> freq(letters);
	for (char c: s)
		freq[c - 'a']++;
	for (int i = 0; i < letters; i++)
		if (freq[i] & 1)
			count++;
	return (count <= 1) ? "YES" : "NO";
}

int main() {
	string s;
	cin >> s;
	cout << gameOfThrones(s);
	return 0;
}