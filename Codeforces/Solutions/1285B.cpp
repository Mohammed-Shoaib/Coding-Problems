// Problem Code: 1285B

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string just_eat_it(int n, vector<int>& a) {
	long long prefix, suffix;
	prefix = suffix = 0;
	for (int i = 0, j = n - 1; i < n; i++, j--) {
		prefix += a[i];
		suffix += a[j];
		if (prefix <= 0 || suffix <= 0)
			return "NO";
	}
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
		cout << just_eat_it(n, a) << endl;
	}
	return 0;
}