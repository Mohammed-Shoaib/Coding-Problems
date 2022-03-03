// Problem Code: 977A
 
#include <iostream>

using namespace std;

int wrong_subtraction(int n, int k) {
	while (k--) {
		if (n % 10 == 0)
			n /= 10;
		else
			n--;
	}
	return n;
}

int main() {
	int n, k;
	cin >> n >> k;
	cout << wrong_subtraction(n, k);
	return 0;
}