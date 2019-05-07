/*
Problem Statement: https://www.hackerrank.com/challenges/cpp-lower-bound/problem
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string lower_bound_stl(int Y, vector<int> &X) {
	int pos = distance(X.begin(), lower_bound(X.begin(), X.end(), Y));
	return ((X[pos] == Y) ? "Yes " : "No ") + to_string(pos + 1);
}

int main() {
	int N, Q;
	cin >> N;
	vector<int> X(N);
	for (int i = 0; i < N; i++)
		cin >> X[i];
	cin >> Q;
	while (Q--) {
		int Y;
		cin >> Y;
		cout << lower_bound_stl(Y, X) << endl;
	}
	return 0;
}