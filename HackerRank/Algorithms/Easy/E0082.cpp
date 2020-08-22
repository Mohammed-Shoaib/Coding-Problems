/*
Problem Statement: https://www.hackerrank.com/challenges/lonely-integer/problem
*/

#include <iostream>
#include <vector>

using namespace std;

int lonelyinteger(vector<int> a) {
	int unique = 0;
	for (int i = 0; i < a.size(); i++)
		unique ^= a[i];
	return unique;
}

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cout << lonelyinteger(a);
}