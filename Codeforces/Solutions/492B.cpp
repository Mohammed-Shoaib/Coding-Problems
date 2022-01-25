// Problem Code: 492B
 
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

double vanya_and_lanterns(int n, int l, vector<int>& a) {
	sort(a.begin(), a.end());
	double d, max_d = max(a.front(), l - a.back());
	
	for (int i = 1; i < n; i++) {
		d = (a[i] - a[i - 1]) / 2.0;
		max_d = max(d, max_d);
	}
	
	return max_d;
}

int main() {
	cout << fixed << setprecision(10);
	int n, l;
	cin >> n >> l;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cout << vanya_and_lanterns(n, l, a);
	return 0;
}