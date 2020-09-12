// Problem Code: abc170_c

#include <iostream>
#include <cmath>
#include <unordered_set>
#include <limits>

using namespace std;

int forbidden_list(int X, int N, unordered_set<int>& p) {
	int ele, min_d = numeric_limits<int>::max();

	for (int i = 0; i <= 101; i++)
		if (!p.count(i) && abs(X - i) < min_d) {
			ele = i;
			min_d = abs(X - i);
		}

	return ele;
}

int main() {
	int X, N;
	cin >> X >> N;
	unordered_set<int> p(N);
	for (int i = 0; i < N; i++) {
		int val;
		cin >> val;
		p.insert(val);
	}
	cout << forbidden_list(X, N, p);
	return 0;
}