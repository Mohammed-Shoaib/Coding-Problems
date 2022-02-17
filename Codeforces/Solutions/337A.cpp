// Problem Code: 337A
 
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int puzzles(int n, int m, vector<int>& f) {
	int diff = numeric_limits<int>::max();
	sort(f.begin(), f.end());
	for (int i = 0; i + n - 1 < m; i++)
		diff = min(f[i + n - 1] - f[i], diff);
	return diff;
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> f(m);
	for (int i = 0; i < m; i++)
		cin >> f[i];
	cout << puzzles(n, m, f);
	return 0;
}