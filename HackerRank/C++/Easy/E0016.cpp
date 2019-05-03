/*
Problem Statement: https://www.hackerrank.com/challenges/vector-sort/problem
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void vector_sort(vector<int> &V) {
	sort(V.begin(), V.end());
}

int main() {
	int N;
	cin >> N;
	vector<int> V(N);
	for (int i = 0; i < N; i++)
		cin >> V[i];
	vector_sort(V);
	for (int i = 0; i < N; i++)
		cout << V[i] << " ";
	return 0;
}