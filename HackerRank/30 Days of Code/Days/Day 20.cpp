/*
Problem Statement: https://www.hackerrank.com/challenges/30-sorting/problem
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void bubble_sort(int n, vector<int>& a) {
	int swaps = 0;
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - i - 1; j++)
			if (a[j] > a[j + 1]) {
				swap(a[j], a[j + 1]);
				swaps++;
			}
	cout << "Array is sorted in " << swaps << " swaps." << endl;
	cout << "First Element: " << a[0] << endl;
	cout << "Last Element: " << a[n - 1] << endl;
}

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	bubble_sort(n, a);
}