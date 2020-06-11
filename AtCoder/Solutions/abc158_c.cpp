// Problem Code: abc158_c

#include <iostream>
#include <cmath>

using namespace std;

int tax_increase(int A, int B) {
	for (int i = ceil(A / 0.08); int(i * 0.08) == A; i++)
		if (int(i * 0.1) == B)
			return i;
	return -1;
}

int main() {
	int A, B;
	cin >> A >> B;
	cout << tax_increase(A, B);
	return 0;
}