// Problem Code: 1370D

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int odd_even_subsequence(int n, int k, vector<int>& a) {
	int mid, low = 0, high = *max_element(a.begin(), a.end());

	// helper function
	auto good = [&](int x) -> bool {
		for (int turn: {0, 1}) {
			int len = 0;
			for (int& num: a)
				if (!turn || num <= x) {
					len++;
					turn = !turn;
				}
			if (len >= k)
				return true;
		}
		return false;
	};

	// binary search
	while (low < high) {
		mid = (low + high) / 2;
		if (good(mid))
			high = mid;
		else
			low = mid + 1;
	}

	return high;
}

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cout << odd_even_subsequence(n, k, a);
	return 0;
}