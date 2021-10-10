// Problem Code: 1283E

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void parties(int n, vector<int>& x) {
	int min_h, max_h;
	vector<bool> taken(n + 2);
	sort(x.begin(), x.end());
	
	// Minimum calculation
	for (int i = 0; i < n; i++) {
		if (taken[x[i] - 1] || taken[x[i]])
			continue;
		taken[x[i] + 1] = true;
	}
	min_h = count(taken.begin(), taken.end(), true);

	// Maximum calculation
	fill(taken.begin(), taken.end(), false);
	for (int i = 0; i < n; i++) {
		if (!taken[x[i] - 1])
			taken[x[i] - 1] = true;
		else if (!taken[x[i]])
			taken[x[i]] = true;
		else
			taken[x[i] + 1] = true;
	}
	max_h = count(taken.begin(), taken.end(), true);

	cout << min_h << " " << max_h;
}

int main() {
	int n;
	cin >> n;
	vector<int> x(n);
	for (int i = 0; i < n; i++)
		cin >> x[i];
	parties(n, x);
	return 0;
}