#include <iostream>
#include <cmath>
#include <functional>

using namespace std;

int length(__int128 Y) {
	int len = (Y == 0);
	while (Y) {
		len++;
		Y /= 10;
	}
	return len;
}

uint64_t generate(uint64_t X, int len) {
	__int128 Y = 0;
	pair<int, uint64_t> p10 = {0, 1};
	
	for (uint64_t x = exchange(X, 0); length(Y) <= len; x++) {
		X = Y;
		int len_x = length(x);
		while (p10.first < len_x) {
			p10.first++;
			p10.second *= 10;
		}
		Y = Y * p10.second + x;
	}
	
	return X;
}

uint64_t roaring_years(uint64_t Y) {
	int n = length(Y);
	uint64_t roar = numeric_limits<uint64_t>::max();
	
	// helper function
	auto binary_search = [&](int len, uint64_t low, uint64_t high) {
		while (low <= high) {
			uint64_t mid = low + (high - low) / 2;
			
			for (uint64_t x = mid; x >= low && mid - x < 10; x--) {
				uint64_t gen_x = generate(x, len);
				if (length(x) < n && gen_x > Y)
					roar = min(gen_x, roar);
			}
			
			if (length(mid) < n && generate(mid, len) > Y)
				high = mid - 1;
			else
				low = mid + 1;
		}
	};
	
	// base case
	if (Y < 10)
		return 12;
	
	for (int i = n; i > 0; i--) {
		uint64_t p10 = 1;
		for (int j = 1; j < n - i; j++)
			p10 *= 10;
		uint64_t low = p10, high = 10 * low - 1;
		binary_search(n, low, high);
		binary_search(n + 1, low, high);
	}
	
	return roar;
}

int main() {
	int T;
	cin >> T;
	for (int x = 1; x <= T; x++) {
		uint64_t Y;
		cin >> Y;
		cout << "Case #" << x << ": " << roaring_years(Y) << endl;
	}
	return 0;
}