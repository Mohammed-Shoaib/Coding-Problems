// Problem Code: 486A
 
#include <iostream>

using namespace std;

int64_t calculating_function(int64_t n) {
	return n / 2 - n * (n & 1);
}

int main() {
	int64_t n;
	cin >> n;
	cout << calculating_function(n);
	return 0;
}