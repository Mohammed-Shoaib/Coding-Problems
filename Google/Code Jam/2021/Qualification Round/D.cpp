#include <iostream>
#include <cassert>
#include <random>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int query(int i, int j, int k) {
	int median;
	cout << i << " " << j << " " << k << endl;
	cin >> median;
	assert(median != -1);
	return median;
}

void ternary_search(int x, int beg, int end, vector<int>& L) {
	int a, b, median, size = end - beg;
	
	// base cases
	if (size == 0) {
		L.insert(L.begin() + beg, x);
		return;
	} else if (size == 1) {
		if (beg > 0)
			ternary_search(x, beg - 1, end, L);
		else
			ternary_search(x, beg, end + 1, L);
		return;
	}
	
	// split the array into 3 parts
	int len = size / 3;
	a = beg + len;
	b = beg + 2 * len + (len == 0);
	
	// ternary search the next part
	median = query(x, L[a], L[b]);
	if (median == L[a])
		ternary_search(x, beg, a, L);
	else if (median == x)
		ternary_search(x, a + 1, b, L);
	else
		ternary_search(x, b + 1, end, L);
}

void median_sort(int N, int Q) {
	int verdict;
	vector<int> L, P(N);
	mt19937 gen(random_device{}());
	
	// randomized shuffle
	iota(P.begin(), P.end(), 1);
	shuffle(P.begin(), P.end(), gen);
	for (int x: {0, 1}) {
		L.push_back(P.back());
		P.pop_back();
	}
	
	// find position for each element
	for (int& x: P)
		ternary_search(x, 0, L.size(), L);
	
	for (int& x: L)
		cout << x << " ";
	cout << endl;
	
	cin >> verdict;
	assert(verdict == 1);
}

int main() {
	int T, N, Q;
	cin >> T >> N >> Q;
	for (int x = 1; x <= T; x++)
		median_sort(N, Q);
	return 0;
}