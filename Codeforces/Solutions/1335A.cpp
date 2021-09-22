// Problem Code: 1335A

#include <iostream>

using namespace std;

int candies(int n) {
	return (n - 1) / 2;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << candies(n) << endl;
	}
	return 0;
}