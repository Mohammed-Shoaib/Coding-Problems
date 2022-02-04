// Problem Code: 1368A
 
#include <iostream>

using namespace std;

int c_plus_equal(int a, int b, int n) {
	int cnt = 0;
	
	if (b < a)
		swap(a, b);
	
	while (b <= n) {
		a += b;
		swap(a, b);
		cnt++;
	}
	
	return cnt;
}

int main() {
	int T;
	cin >> T;
	
	while (T--) {
		int a, b, n;
		cin >> a >> b >> n;
		cout << c_plus_equal(a, b, n) << endl;
	}
	
	return 0;
}
