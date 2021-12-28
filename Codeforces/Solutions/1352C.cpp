// Problem Code: 1352C
 
#include <iostream>

using namespace std;

int kth_not_divisible_by_n(int n, int k) {
	return k + (k - 1) / (n - 1);
}

int main() {
	int t;
	cin >> t;
	
	while (t--) {
		int n, k;
		cin >> n >> k;
		cout << kth_not_divisible_by_n(n, k) << endl;
	}
	
	return 0;
}