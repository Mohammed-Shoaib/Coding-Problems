// Problem Code: abc172_a

#include <iostream>

using namespace std;

int calc(int a) {
	return a * (1 + a * (1 + a));
}

int main() {
	int a;
	cin >> a;
	cout << a + a * a + a * a * a;
	return 0;
}