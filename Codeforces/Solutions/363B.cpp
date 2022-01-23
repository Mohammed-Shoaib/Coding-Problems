// Problem Code: 363B
 
#include <iostream>
#include <vector>
#include <numeric>
#include <utility>

using namespace std;

int fence(int n, int k, vector<int>& h) {
	int sum = accumulate(h.begin(), h.begin() + k, 0);
	pair<int, int> pos = {0, sum};
	
	for (int i = k; i < n; i++) {
		sum -= h[i - k];
		sum += h[i];
		if (pos.second > sum)
			pos = {i - k + 1, sum};
	}
	
	return 1 + pos.first;
}

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> h(n);
	for (int i = 0; i < n; i++)
		cin >> h[i];
	cout << fence(n, k, h);
	return 0;
}
