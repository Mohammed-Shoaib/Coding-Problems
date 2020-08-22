/*
Problem Statement: https://www.hackerrank.com/challenges/almost-sorted/problem
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool check(vector<int> &arr) {
	for (int i = 0; i < arr.size() - 1; i++)
		if (arr[i] > arr[i + 1])
			return false;
	return true;
}

void almostSorted(vector<int> &arr) {
	int i, j;
	for (i = 0; i < arr.size() - 1; i++)
		if (arr[i] > arr[i + 1])
			break;
	for (j = arr.size() - 1; j > 0; j--)
		if (arr[j - 1] > arr[j])
			break;
	if (i > j) {
		cout << "yes" << endl;
		return;
	}
	swap(arr[i], arr[j]);
	if (check(arr)) {
		cout << "yes" << endl;
		cout << "swap " << i + 1 << " " << j + 1 << endl;
		return;
	}
	reverse(arr.begin() + i + 1, arr.begin() + j);
	if (check(arr)) {
		cout << "yes" << endl;
		cout << "reverse " << i + 1 << " " << j + 1 << endl;
	}
	else
		cout << "no" << endl;
	return;
}

int main() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	almostSorted(arr);
	return 0;
}