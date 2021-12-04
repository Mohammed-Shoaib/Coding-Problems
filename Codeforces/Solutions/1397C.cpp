// Problem Code: 1397C

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

void multiples_of_length(int64_t n, vector<int>& a) {
	// first operation
	cout << 1 << " " << 1 << '\n';
	cout << -exchange(a[0], 0) << '\n';
	
	// second operation
	cout << 1 << " " << n << '\n';
	for (int i = 0; i < n; i++)
		cout << -n * a[i] << " ";
	cout << '\n';
	
	// third operation
	if (n == 1)
		cout << 1 << " " << 1 << '\n' << 0;
	else {
		cout << 2 << " " << n << '\n';
		for (int i = 1; i < n; i++)
			cout << (n - 1) * a[i] << " ";
	}
	cout << '\n';
}

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	multiples_of_length(n, a);
	return 0;
}