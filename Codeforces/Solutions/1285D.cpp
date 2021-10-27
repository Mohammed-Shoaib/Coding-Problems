// Problem Code: 1285D

#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;

int bit(int b) {
	return 1 << b;
}
 
int evil(int b, vector<int>& a) {
	if (b < 0)
		return 0;
	vector<int> on, off;
	for (int& num: a) {
		if (num & bit(b))
			on.push_back(num);
		else
			off.push_back(num);
	}
	if (on.empty())
		return evil(b - 1, off);
	else if (off.empty())
		return evil(b - 1, on);
	else
		return min(evil(b - 1, on), evil(b - 1, off)) + bit(b);
}
 
int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cout << evil(31, a);
	return 0;
}