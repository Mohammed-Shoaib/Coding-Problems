// Problem Code: 996A
 
#include <iostream>
#include <vector>

using namespace std;

int hit_the_lottery(int n) {
	int bills = 0;
	vector<int> coins = {100, 20, 10, 5, 1};
	
	for (int& coin: coins) {
		bills += n / coin;
		n -= coin * (n / coin);
	}
	
	return bills;
}

int main() {
	int n;
	cin >> n;
	cout << hit_the_lottery(n);
	return 0;
}