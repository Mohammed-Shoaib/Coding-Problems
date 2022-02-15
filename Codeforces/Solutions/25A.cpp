// Problem Code: 25A
 
#include <iostream>
#include <vector>

using namespace std;

int iq_test(int n, vector<int>& a) {
	int odd_cnt = 0;
	
	for (int i = 0; i < n; i++)
		odd_cnt += a[i] & 1;
	
	for (int i = 0; i < n; i++)
		if ((odd_cnt == 1) == (a[i] & 1))
			return i + 1;
	
	return -1;
}

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cout << iq_test(n, a);
	return 0;
}