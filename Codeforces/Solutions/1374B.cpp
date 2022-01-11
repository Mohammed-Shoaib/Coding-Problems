// Problem Code: 1374B
 
#include <iostream>

using namespace std;

int multiply_by_2_divide_by_6(int n) {
	int moves = 0;
	
	while (n && n % 6 == 0) {
		moves++;
		n /= 6;
	}
	
	while (n && n % 3 == 0) {
		moves += 2;
		n /= 3;
	}
	
	return (n == 1) ? moves : -1;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << multiply_by_2_divide_by_6(n) << endl;
	}
	return 0;
}
