// Problem Code: 268A
 
#include <iostream>
#include <vector>

using namespace std;

int games(int n, vector<int>& h, vector<int>& a) {
	int cnt = 0;
	
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++) {
			cnt += h[i] == a[j];
			cnt += a[i] == h[j];
		}
	
	return cnt;
}

int main() {
	int n;
	cin >> n;
	vector<int> h(n), a(n);
	for (int i = 0; i < n; i++)
		cin >> h[i] >> a[i];
	cout << games(n, h, a);
	return 0;
}