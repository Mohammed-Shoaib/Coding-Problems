/*
Problem Statement: https://www.hackerrank.com/challenges/beautiful-pairs/problem
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int beautifulPairs(vector<int> &A, vector<int> &B) {
	int n, common;
	unordered_map<int, int> cntA, cntB;
	common = 0;
	n = A.size();

	for (int i = 0; i < n; i++) {
		cntA[A[i]]++;
		cntB[B[i]]++;
	}

	for (auto cnt: cntA)
		common += min(cnt.second, cntB[cnt.first]);

	return (common == n) ? common - 1 : common + 1;
}

int main() {
	int n;
	cin >> n;
	vector<int> A(n), B(n);
	for (int i = 0; i < n; i++)
		cin >> A[i];
	for (int i = 0; i < n; i++)
		cin >> B[i];
	cout << beautifulPairs(A, B);
	return 0;
}