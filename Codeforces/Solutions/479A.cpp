// Problem Code: 479A
 
#include <iostream>
#include <algorithm>

using namespace std;

int expression(int a, int b, int c) {
	return max({
		(a + b) * c,
		a * (b + c),
		a + b + c,
		a * b * c
	});
}

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	cout << expression(a, b, c);
	return 0;
}