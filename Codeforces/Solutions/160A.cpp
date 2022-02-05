// Problem Code: 160A
 
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int twins(int n, vector<int>& a) {
	int pos = n - 1;
	vector<int> prefix(n + 1);
	sort(a.begin(), a.end());
	
	for (int i = 0; i < n; i++)
		prefix[i + 1] = a[i] + prefix[i];
	
	while (prefix[n] <= 2 * prefix[pos])
		pos--;
	
	return n - pos;
}

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cout << twins(n, a);
	return 0;
}