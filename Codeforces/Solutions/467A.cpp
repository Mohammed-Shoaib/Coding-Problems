// Problem Code: 467A
 
#include <iostream>
#include <vector>

using namespace std;

int george_and_accommodation(int n, vector<int>& p, vector<int>& q) {
	int cnt = 0;
	for (int i = 0; i < n; i++)
		cnt += q[i] - p[i] >= 2;
	return cnt;
}

int main() {
	int n;
	cin >> n;
	vector<int> p(n), q(n);
	for (int i = 0; i < n; i++)
		cin >> p[i] >> q[i];
	cout << george_and_accommodation(n, p, q);
	return 0;
}