// Problem Code: 1353C
 
#include <iostream>

using namespace std;

int64_t sum_of_squares(int64_t n) {
	return n * (n + 1) * (2 * n + 1) / 6;
}

int64_t board_moves(int n) {
	return 8 * sum_of_squares(n / 2);
}

int main() {
	int t;
	cin >> t;
	
	while (t--) {
		int n;
		cin >> n;
		cout << board_moves(n) << endl;
	}
	
	return 0;
}