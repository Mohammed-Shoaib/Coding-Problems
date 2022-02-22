// Problem Code: 466A
 
#include <iostream>
#include <algorithm>

using namespace std;

int cheap_travel(int n, int m, int a, int b) {
	if (m * a <= b)
		return n * a;
	else
		return (n / m) * b + min((n % m) * a, b);
}

int main() {
	int n, m, a, b;
	cin >> n >> m >> a >> b;
	cout << cheap_travel(n, m, a, b);
	return 0;
}
