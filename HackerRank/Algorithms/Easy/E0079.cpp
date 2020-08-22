/*
Problem Statement: https://www.hackerrank.com/challenges/priyanka-and-toys/problem
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int toys(vector<int> w) {
	int pos, containers;
	pos = 0;
	containers = 1;
	sort(w.begin(), w.end());
	for (int i = 1; i < w.size(); i++)
		if (w[i] > w[pos] + 4) {
			pos = i;
			containers++;
		}
	return containers;
}

int main() {
	int n;
	cin >> n;
	vector<int> w(n);
	for (int i = 0; i < n; i++)
		cin >> w[i];
	cout << toys(w);
	return 0;
}