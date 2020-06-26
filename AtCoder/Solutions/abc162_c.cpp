// Problem Code: abc162_c

#include <iostream>
#include <numeric>

using namespace std;

long long tuples(int K) {
	long long sum = 0;
	for (int a = 1; a <= K; a++)
		for (int b = 1; b <= K; b++)
			for (int c = 1; c <= K; c++)
				sum += gcd(a, gcd(b, c));
	return sum;
}

int main() {
	int K;
	cin >> K;
	cout << tuples(K);
	return 0;
}