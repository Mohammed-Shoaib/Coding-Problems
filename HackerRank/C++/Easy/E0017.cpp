/*
Problem Statement: https://www.hackerrank.com/challenges/vector-erase/problem
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void vector_erase(int x, int a, int b, vector<int> &V) {
	V.erase(V.begin() + x - 1);
	V.erase(V.begin() + a - 1, V.begin() + b - 1);
}

int main() {
	int N, x, a, b;
	cin >> N;
	vector<int> V(N);
	for (int i = 0; i < N; i++)
		cin >> V[i];
	cin >> x >> a >> b;
	vector_erase(x, a, b, V);
	cout << V.size() << endl;
	for (int i = 0; i < V.size(); i++)
		cout << V[i] << " ";
	return 0;
}