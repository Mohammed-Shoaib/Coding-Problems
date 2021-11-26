// Problem Code: 1328C

#include <iostream>
#include <string>

using namespace std;

void ternary_xor(int n, string& x) {
	bool flag = false;
	string a(n, '0'), b(n, '0');
	
	for (int i = 0; i < n; i++) {
		if (x[i] == '2') {
			if (!flag)
				a[i] = b[i] = '1';
			else
				a[i] = '2';
		}
		else if (x[i] == '1') {
			if (!flag) {
				b[i] = '1';
				flag = true;
			}
			else
				a[i] = '1';
		}
	}
	
	cout << a << endl;
	cout << b << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		string x;
		cin >> n >> x;
		ternary_xor(n, x);
	}
	return 0;
}