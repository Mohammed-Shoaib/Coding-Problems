// Problem Code: 1272D

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int max_length(int n, vector<int>& a) {
	int max_len;
	vector<int> l(n, 1), r(n, 1);

	// Length of increasing sequence starting at position i
	for (int i = 1; i < n; i++)
		if (a[i - 1] < a[i])
			r[i] += r[i - 1];
	
	// Length of increasing sequence ending at position i
	for (int i = n - 2; i >= 0; i--)
		if (a[i] < a[i + 1])
			l[i] += l[i + 1];
	
	// Do not remove any elements
	max_len = *max_element(l.begin(), l.end());
	
	// Remove element at position i
	for (int i = 1; i < n - 1; i++)
		if (a[i - 1] < a[i + 1])
			max_len = max(r[i - 1] + l[i + 1], max_len);
	
	return max_len;
}

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cout << max_length(n, a);
	return 0;
}