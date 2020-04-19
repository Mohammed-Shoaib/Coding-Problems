#include <iostream>
#include <utility>

using namespace std;

bool is_sorted(long long N) {
	int last, r = 9;
	while (N > 0) {
		last = exchange(r, N % 10);
		if (r > last)
			return false;
		N /= 10;
	}
	return true;
}

long long tidy_numbers(long long N) {
	long long sub = 10;
	while (!is_sorted(N)) {
		N -= N % sub + 1;
		sub *= 10;
	}
	return N;
}

int main() {
	int T;
	cin >> T;
	for (int x = 1; x <= T; x++) {
		long long N;
		cin >> N;
		cout << "Case #" << x << ": " << tidy_numbers(N) << endl;
	}
	return 0;
}