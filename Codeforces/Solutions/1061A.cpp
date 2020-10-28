// Problem Code: 1061A

#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int S, coins;
	double n;
	cin >> n >> S;
	coins = ceil(S/n);
	cout << coins;
	return 0;
}