// Problem Code: 1399B

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long gifts_fixing(int n, vector<int>& a, vector<int>& b) {
	int min_a, min_b;
	long long moves = 0;
	min_a = *min_element(a.begin(), a.end());
	min_b = *min_element(b.begin(), b.end());

	for (int i = 0; i < n; i++)
		moves += max(a[i] - min_a, b[i] - min_b);

	return moves;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n), b(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		for (int i = 0; i < n; i++)
			cin >> b[i];
		cout << gifts_fixing(n, a, b) << endl;
	}	
	return 0;
}