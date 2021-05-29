// Problem Code: 1527A

#include <iostream>

using namespace std;

unsigned int highest_set_bit(unsigned int num) {
	// num = 1XXXXXXX XXXXXXXX XXXXXXXX XXXXXXXX
	num |= (num >> 1);			// 11XXXXXX XXXXXXXX XXXXXXXX XXXXXXXX
	num |= (num >> 2);			// 1111XXXX XXXXXXXX XXXXXXXX XXXXXXXX
	num |= (num >> 4);			// 11111111 XXXXXXXX XXXXXXXX XXXXXXXX
	num |= (num >> 8);			// 11111111 11111111 XXXXXXXX XXXXXXXX
	num |= (num >> 16);			// 11111111 11111111 11111111 11111111
	return num - (num >> 1);	// 10000000 00000000 00000000 00000000
}

int and_then_there_were_k(int n) {
	int k = highest_set_bit(n);
	return k - 1;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << and_then_there_were_k(n) << endl;
	}
	return 0;
}