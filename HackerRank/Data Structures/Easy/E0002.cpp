/*
Problem Code: https://www.hackerrank.com/challenges/2d-array/problem
*/

#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

int hourGlass(int i, int j, vector< vector<int> > &arr) {
	int sum = 0;
	for (int m = i; m < i + 3; m++)
		for (int n = j; n < j + 3; n++)
			sum += arr[m][n];
	sum -= arr[i + 1][j] + arr[i + 1][j + 2];
	return sum;
}

int hourglassSum(vector< vector<int> > &arr) {
	int maxSum = numeric_limits<int>::min();
	for (int i = 0; i < arr.size() - 2; i++)
		for (int j = 0; j < arr[i].size() - 2; j++)
			maxSum = max(hourGlass(i, j, arr), maxSum);
	return maxSum;
}

int main() {
	vector< vector<int> > arr(6, vector<int>(6));
	for (int i = 0; i < arr.size(); i++)
		for (int j = 0; j < arr[i].size(); j++)
			cin >> arr[i][j];
	cout << hourglassSum(arr);
    return 0;
}