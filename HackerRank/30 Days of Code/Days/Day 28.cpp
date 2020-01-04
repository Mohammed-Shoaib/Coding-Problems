/*
Problem Statement: https://www.hackerrank.com/challenges/30-regex-patterns/problem
*/

#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <algorithm>

using namespace std;

bool gmail(string& email) {
	regex re(".+@gmail\\.com$");
	return regex_match(email, re);
}

int main() {
	int N;
	cin >> N;
	string name, email;
	vector<string> names;
	for (int i = 0; i < N; i++) {
		cin >> name >> email;
		if (gmail(email))
			names.push_back(name);
	}
	sort(names.begin(), names.end());
	for (string& name: names)
		cout << name << endl;
	return 0;
}