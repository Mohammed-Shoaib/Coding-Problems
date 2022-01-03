// Problem Code: 1333B

#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

string kind_anton(int n, vector<int>& a, vector<int>& b) {
	int pos, neg;
	pos = distance(a.begin(), find(a.begin(), a.end(),  1));
	neg = distance(a.begin(), find(a.begin(), a.end(), -1));

	for (int i = 0; i < n; i++)
		if (a[i] < b[i] && pos >= i || a[i] > b[i] && neg >= i)
			return "NO";

	return "YES";
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
		cout << kind_anton(n, a, b) << endl;
	}
	return 0;
}