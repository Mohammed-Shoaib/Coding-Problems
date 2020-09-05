// Problem Code: 1201B

#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

string zero_array(int n, vector<int>& a) {
	int64_t sum, mx;
	sum = accumulate(a.begin(), a.end(), static_cast<int64_t>(0));
	mx = *max_element(a.begin(), a.end());
	return (mx > sum - mx || sum & 1) ? "NO" : "YES";
}

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cout << zero_array(n, a);
	return 0;
}