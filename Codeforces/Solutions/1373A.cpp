// Problem Code: 1373A

#include <iostream>
#include <utility>

using namespace std;

pair<int, int> donut_shops(long long a, int b, int c) {
	if (a >= c)
		return {-1, b};
	else if (b * a <= c)
		return {1, -1};
	else
		return {1, b};
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int a, b, c;
		cin >> a >> b >> c;
		pair<int, int> res = donut_shops(a, b, c);
		cout << res.first << " " << res.second << endl;
	}
	return 0;
}