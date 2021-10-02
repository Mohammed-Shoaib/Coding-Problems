// Problem Code: 1265B

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string range(int n, vector<int>& p) {
	string s;
	int min_pos, max_pos;
	vector<int> pos(n + 1);
	min_pos = n - 1;
	max_pos = 0;
	
	// Store the position of each number
	for (int i = 0; i < n; i++)
		pos[p[i]] = i;
	
	// Check if the length of range is equal to number
	for (int i = 1; i <= n; i++) {
		min_pos = min(pos[i], min_pos);
		max_pos = max(pos[i], max_pos);
		s += (max_pos - min_pos + 1 == i) + '0';
	}

	return s;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> p(n);
		for (int i = 0; i < n; i++)
			cin >> p[i];
		cout << range(n, p) << endl;
	}
	return 0;
}