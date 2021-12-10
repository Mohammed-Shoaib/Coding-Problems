// Problem Code: 1283B

#include <iostream>

using namespace std;

int candies_division(int n, int k) {
	int candy = n - n % k;
	candy += min(n % k, k / 2);
	return candy;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		cout << candies_division(n, k) << endl;
	}
	return 0;
}