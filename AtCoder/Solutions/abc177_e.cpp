// Problem Code: abc177_e

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

string coprime(int N, vector<int>& A) {
	int g = A[0], mx = *max_element(A.begin(), A.end());
	vector<bool> fact(mx);
	
	// gcd of all the elements
	for (int& x: A)
		g = gcd(x, g);
	if (g > 1)
		return "not coprime";
	
	// check for setwise coprime
	for (int x: A) {
		bool not_ok = false;
		for (int y = 2; y * y <= x; y++)
			if (x % y == 0) {
				while (x % y == 0)
					x /= y;
				not_ok |= fact[y];
				fact[y] = true;
			}
		if (x > 1) {
			not_ok |= fact[x];
			fact[x] = true;
		}
		if (not_ok)
			return "setwise coprime";
	}
	
	return "pairwise coprime";
}

int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; i++)
		cin >> A[i];
	cout << coprime(N, A);
	return 0;
}