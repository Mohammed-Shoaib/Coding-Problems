/*
Problem Statement: https://www.hackerrank.com/challenges/30-2d-arrays/problem
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int hourglass(int n, vector< vector<int> >& A) {
	vector<int> glass(16);

	for (int i = 0; i < glass.size(); i++)
		for (int j = i / 4, m = 0; m < 3; j++, m++)
			for (int k = i % 4, n = 0; n < 3; k++, n++) {
				if (m == 1) {
					glass[i] += A[j][k + 1];
					break;
				}
				glass[i] += A[j][k];
			}
	
	return *max_element(glass.begin(), glass.end());
}

int main() {
	int n = 6;
	vector< vector<int> > A(n, vector<int>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> A[i][j];
	cout << hourglass(n, A);
	return 0;
}