// Problem Code: 1399A

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string remove_smallest(int n, vector<int>& a) {
	sort(a.begin(), a.end());
	for (int i = 1; i < n; i++)
		if (a[i] - a[i - 1] > 1)
			return "NO";
	return "YES";
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
		cout << remove_smallest(n, a) << endl;
	}
	return 0;
}