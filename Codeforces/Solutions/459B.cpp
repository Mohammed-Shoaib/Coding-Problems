// Problem Code: 459B
 
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void pashmak_and_flowers(int n, vector<int>& b) {
	int64_t ways, cnt_min, cnt_max;
	auto [min, max] = minmax_element(b.begin(), b.end());
	cnt_min = count(b.begin(), b.end(), *min);
	cnt_max = count(b.begin(), b.end(), *max);
	
	if (*min == *max)
		ways = cnt_min * (cnt_min - 1) / 2;
	else
		ways = cnt_min * cnt_max;
	
	cout << *max - *min << " " << ways << endl;
}

int main() {
	int n;
	cin >> n;
	vector<int> b(n);
	
	for (int& x: b)
		cin >> x;
	
	pashmak_and_flowers(n, b);
	
	return 0;
}
