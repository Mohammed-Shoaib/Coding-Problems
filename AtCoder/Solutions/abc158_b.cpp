// Problem Code: abc158_b

#include <iostream>
#include <algorithm>

using namespace std;

long long count_balls(long long N, long long A, long long B) {
	return A * (N / (A + B)) + min(A, N % (A + B));
}

int main() {
	long long N, A, B;
	cin >> N >> A >> B;
	cout << count_balls(N, A, B);
	return 0;
}