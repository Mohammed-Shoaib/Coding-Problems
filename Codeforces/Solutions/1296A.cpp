// Problem Code: 1296A

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string odd_sum(int n, vector<int>& a) {
	bool odd, even;
	odd = even = false;
	for (int num: a) {
		if (num & 1)
			odd = true;
		else
			even = true;
	}
	return (odd && ((n & 1) || even)) ? "YES" : "NO";
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
		cout << odd_sum(n, a) << endl;
	}
	return 0;
}