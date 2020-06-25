// Problem Code: abc162_b

#include <iostream>

using namespace std;

long long fizz_buzz(int N) {
	long long sum = 0;
	for (int i = 1; i <= N; i++) 
		if (i % 3 != 0 && i % 5 != 0)
			sum += i;
	return sum;
}

int main() {
	int N;
	cin >> N;
	cout << fizz_buzz(N);
	return 0;
}