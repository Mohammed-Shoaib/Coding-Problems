// Problem Code: 1A

#include <iostream>

using namespace std;

long long ceil(int a, int b) {
	return (a + b - 1) / b;
}

long long theatre_square(int n, int m, int a) {
	return ceil(n, a) * ceil(m, a);
}

int main() {
	int n, m, a;
	cin >> n >> m >> a;
	cout << theatre_square(n, m, a);
	return 0;
}