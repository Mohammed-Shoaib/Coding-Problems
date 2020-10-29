// Problem Code: 1080A

#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int n, sheets;
	double k;
	cin >> n >> k;
	sheets = ceil(2*n/k) + ceil(5*n/k) + ceil(8*n/k);
	cout << sheets;
	return 0;
}