// Problem Code: 1397D

#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

string stoned_game(int n, vector<int>& a) {
	int sum, mx;
	sum = accumulate(a.begin(), a.end(), 0);
	mx = *max_element(a.begin(), a.end());
	return (mx > sum - mx || sum & 1) ? "T" : "HL";
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		cout << stoned_game(n, a) << '\n';
	}
	return 0;
}