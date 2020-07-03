// Problem Code: 1374B

#include <iostream>

using namespace std;

int multiply_or_divide(int n) {
	int cnt_2, cnt_3;
	cnt_2 = cnt_3 = 0;
	while (n % 2 == 0) {
		cnt_2++;
		n /= 2;
	}
	while (n % 3 == 0) {
		cnt_3++;
		n /= 3;
	}
	if (n > 1 || cnt_2 > cnt_3)
		return -1;
	else
		return 2 * cnt_3 - cnt_2;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << multiply_or_divide(n) << endl;
	}
	return 0;
}