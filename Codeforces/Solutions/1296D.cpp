// Problem Code: 1296D

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int fight_monsters(int a, int b, int k, int n, vector<int>& h) {
	int points = 0;
	
	for (int i = 0; i < n; i++) {
		h[i] %= a + b;
		if (h[i] == 0)
			h[i] += a + b;
		h[i] = (h[i] + a - 1) / a - 1;
	}
	
	sort(h.begin(), h.end());
	accumulate(h.begin(), h.end(), 0, [&](int sum, int num) {
		if (sum + num <= k)
			points++;
		else
			num = 0;
		return sum + num;
	});
	
	return points;
}

int main() {
	int n, a, b, k;
	cin >> n >> a >> b >> k;
	vector<int> h(n);
	for (int i = 0; i < n; i++)
		cin >> h[i];
	cout << fight_monsters(a, b, k, n, h);
	return 0;
}