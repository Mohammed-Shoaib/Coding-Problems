// Problem Code: 405A
 
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void gravity_flip(int n, vector<int>& a) {
	sort(a.begin(), a.end());
}

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	gravity_flip(n, a);
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	return 0;
}