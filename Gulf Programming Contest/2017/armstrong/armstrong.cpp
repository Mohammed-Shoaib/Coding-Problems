#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>

using namespace std;

string armstrong(int n) {
	int rem, sum, copy, digits;
	sum = 0;
	copy = n;
	digits = to_string(n).length();
	while (copy != 0) {
		rem = copy % 10;
		sum += pow(rem, digits);
		copy /= 10;
	}
	return (sum == n) ? "yes" : "no";
}

int main() {
	freopen("armstrong.in", "r", stdin);
	freopen("output.out", "w", stdout);
	int k, t = 1;
	cin >> k;
	while (k--) {
		int n;
		cin >> n;
		cout << t << ". " << armstrong(n) << endl;
		t++;
	}
	return 0;
}