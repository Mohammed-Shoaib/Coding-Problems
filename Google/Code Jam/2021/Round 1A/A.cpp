#include <iostream>
#include <string>
#include <vector>

using namespace std;

string increment(string s) {
	int carry = 1, n = s.length();
	
	for (int i = n - 1; i >= 0 && carry; i--) {
		s[i] += carry;
		if (s[i] <= '9')
			carry = 0;
		else {
			s[i] = '0';
			carry = 1;
		}
	}
	if (s.empty())
		s = "0";
	else if (carry)
		s.insert(0, 1, '1');
	
	return s;
}

int append_digits(string& x, string& y) {
	int m, n, ops;
	m = x.length();
	n = y.length();
	ops = m - n;
	
	// x and y are strictly increasing
	if (n > m || m == n && x < y)
		return 0;
	
	// append zeros if prefixes are not the same
	for (int i = 0; i < min(m, n); i++)
		if (x[i] != y[i]) {
			ops += (x[i] > y[i]);
			y += string(ops, '0');
			return ops;
		}
	
	// prefix is the same
	string sub, suffix;
	sub = x.substr(y.length());
	suffix = increment(sub);
	
	if (sub.length() == suffix.length()) {
		// suffix is not all nines
		y += suffix;
		return suffix.length();
	} else {
		// suffix is all nines, appending zeros is best
		ops++;
		y += string(ops, '0');
		return ops;
	}
}

int append_sort(int N, vector<string>& X) {
	int ops = 0;
	for (int i = 1; i < N; i++)
		ops += append_digits(X[i - 1], X[i]);
	return ops;
}

int main() {
	int T;
	cin >> T;
	for (int x = 1; x <= T; x++) {
		int N;
		cin >> N;
		vector<string> X(N);
		for (string& x: X)
			cin >> x;
		cout << "Case #" << x << ": " << append_sort(N, X) << endl;
	}
	return 0;
}