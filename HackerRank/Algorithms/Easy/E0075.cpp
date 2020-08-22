/*
Problem Statement: https://www.hackerrank.com/challenges/marcs-cakewalk/problem
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

long long marcsCakewalk(vector<int> c) {
	long long miles = 0;
	sort(c.rbegin(), c.rend());
	for (int i = 0; i < c.size(); i++)
		miles += (long long) pow(2, i) * c[i];
	return miles;
}

int main() {
	int n;
	cin >> n;
	vector<int> c(n);
	for (int i = 0; i < n; i++)
		cin >> c[i];
	cout << marcsCakewalk(c);
	return 0;
}