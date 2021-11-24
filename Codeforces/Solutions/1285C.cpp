// Problem Code: 1285C

#include <iostream>
#include <numeric>

using namespace std;

void fadi_and_lcm(long long X) {
	long long a = 1;
	for (long long i = 2; i * i <= X; i++)
		if (X % i == 0 && lcm(i, X / i) == X)
			a = i;
	cout << a << " " << X / a << endl;
}

int main() {
	long long X;
	cin >> X;
	fadi_and_lcm(X);
	return 0;
}