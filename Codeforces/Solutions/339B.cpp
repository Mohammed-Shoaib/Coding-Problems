// Problem Code: 339B
 
#include <iostream>
#include <vector>

using namespace std;

int64_t xenia_and_ringroad(int n, int m, vector<int>& a) {
	int64_t t = a[0] - 1;
	for (int i = 1; i < m; i++) {
		if (a[i] >= a[i - 1])
			t += a[i] - a[i - 1];
		else
			t += n - a[i - 1] + a[i];
	}
	return t;
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> a(m);
	for (int i = 0; i < m; i++)
		cin >> a[i];
	cout << xenia_and_ringroad(n, m, a);
	return 0;
}