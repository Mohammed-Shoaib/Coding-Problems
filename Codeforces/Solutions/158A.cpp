// Problem Code: 158A
 
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>
 
using namespace std;
 
int next_round(int n, int k, vector<int>& a) {
	int n1, n2;
	n1 = distance(a.begin(), lower_bound(a.begin(), a.end(), 0, greater<int>()));
	n2 = distance(a.begin(), upper_bound(a.begin(), a.end(), a[k - 1], greater<int>()));
	return min(n1, n2);
}
 
int main() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cout << next_round(n, k, a);
	return 0;
}