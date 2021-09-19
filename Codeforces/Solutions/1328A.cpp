// Problem Code: 1328A

#include <iostream>

using namespace std;

int divisibility(int a, int b) {
	return (b - (a % b)) % b;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		cout << divisibility(a, b) << endl;
	}
	return 0;
}