// Problem Code: 34B
 
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int sale(int n, int m, vector<int>& a) {
	int money = 0;
	sort(a.begin(), a.end());
	
	for (int i = 0; i < m && a[i] < 0; i++)
		money -= a[i];
	
	return money;
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (int& x: a)
		cin >> x;
	cout << sale(n, m, a);
	return 0;
}
