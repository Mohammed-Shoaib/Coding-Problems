// Problem Code: 1334A

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string A(int n, vector<int>& p, vector<int>& c) {
	int pl, cl;
	pl = cl = 0;
	for (int i = 0; i < n; i++) {
		if (c[i] - cl > p[i] - pl || c[i] < cl || p[i] < pl)
			return "NO";
		pl = p[i];
		cl = c[i];
	}
	return "YES";
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<int> p(n), c(n);
		for (int i = 0; i < n; i++)
			cin >> p[i] >> c[i];
		cout << A(n, p, c) << endl;
	}
	return 0;
}