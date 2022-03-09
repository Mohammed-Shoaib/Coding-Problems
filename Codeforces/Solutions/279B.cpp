// Problem Code: 279B
 
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int books(int n, int t, vector<int>& a) {
	int books, sum, l;
	books = sum = l = 0;
	
	for (int i = 0; i < n; i++) {
		sum += a[i];
		while (sum > t)
			sum -= a[l++];
		books = max(i - l + 1, books);
	}
	
	return books;
}

int main() {
	int n, t;
	cin >> n >> t;
	vector<int> a(n);
	
	for (int& x: a)
		cin >> x;
	
	cout << books(n, t, a);
	
	return 0;
}
