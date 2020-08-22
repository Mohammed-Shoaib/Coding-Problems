/*
Problem Statement: https://www.hackerrank.com/challenges/hackerland-radio-transmitters/problem
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int hackerlandRadioTransmitters(int k, vector<int> &x) {
	int n, i, pos, transmitters;
	n = x.size();
	transmitters = i = 0;
	sort(x.begin(), x.end());

	while (i < n) {
		pos = x[i] + k;
		while (i < n && x[i] <= pos)
			i++;
		pos = x[--i] + k;
		while (i < n && x[i] <= pos)
			i++;
		transmitters++;
	}
	
	return transmitters;
}

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> x(n);
	for (int i = 0; i < n; i++)
		cin >> x[i];
	cout << hackerlandRadioTransmitters(k, x);
	return 0;
}