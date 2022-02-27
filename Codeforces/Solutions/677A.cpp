// Problem Code: 677A
 
#include <iostream>
#include <vector>

using namespace std;

int vanya_and_fence(int n, int h, vector<int>& a) {
	int width = n;
	for (int& x: a)
		width += x > h;
	return width;
}

int main() {
	int n, h;
	cin >> n >> h;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cout << vanya_and_fence(n, h, a);
	return 0;
}