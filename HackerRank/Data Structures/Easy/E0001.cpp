/*
Problem Code: https://www.hackerrank.com/challenges/arrays-ds/problem
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; i++)
		cin >> A[i];
	reverse(A.begin(), A.end());
	for (int i = 0; i < N; i++)
		cout << A[i] << " ";
    return 0;
}