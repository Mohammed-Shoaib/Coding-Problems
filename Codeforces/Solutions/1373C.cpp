// Problem Code: 1373C

#include <iostream>
#include <string>

using namespace std;

long long plus_and_minus(string& s) {
	long long res;
	int sum, mn, n;
	n = s.length();
	res = sum = mn = 0;

	for (int i = 0; i < n; i++) {
		sum += (s[i] == '+') ? 1 : -1;
		if (sum < mn) {
			res += i + 1;
			mn = sum;
		}
	}
	res += n;

	return res;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		cout << plus_and_minus(s) << endl;
	}
	return 0;
}