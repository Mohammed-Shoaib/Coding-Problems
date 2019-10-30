/*
Problem Code: https://www.hackerrank.com/challenges/array-left-rotation/problem
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void leftRotation(int d, vector<int> &a) {
	rotate(a.begin(), a.begin() + d % a.size(), a.end());
}

int main() {
	int n, d;
	cin >> n >> d;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	leftRotation(d, a);
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
    return 0;
}