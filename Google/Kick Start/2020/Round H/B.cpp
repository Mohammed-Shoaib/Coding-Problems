#include <iostream>
#include <cmath>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int64_t boring_numbers(int64_t x) {
	int64_t boring = 0;
	vector<int> d;
	
	while (x)
		d.push_back(exchange(x, x / 10) % 10);
	reverse(d.begin(), d.end());
	
	for (int i = 0; i < d.size(); i++)
		boring += pow(5LL, i + 1);
	
	for (int i = 0; i < d.size(); i++) {
		int len = (10 - d[i] - (i & 1)) / 2;
		boring -= len * pow(5LL, d.size() - i - 1);
		if ((d[i] & 1) == (i & 1))
			break;
	}
	
	return boring;
}

int main() {
	int T;
	cin >> T;
	for (int x = 1; x <= T; x++) {
		int64_t L, R;
		cin >> L >> R;
		cout << "Case #" << x << ": " << boring_numbers(R) - boring_numbers(L - 1) << endl;
	}
	return 0;
}