// Problem Code: 546A
 
#include <iostream>

using namespace std;

int soldier_and_bananas(int k, int n, int w) {
	int cost = k * w * (w + 1) / 2;
	return max(0, cost - n);
}

int main() {
	int k, n, w;
	cin >> k >> n >> w;
	cout << soldier_and_bananas(k, n, w);
	return 0;
}