/*
Problem Code: 1512G
Time: O(mxC • log mxC)
Space: O(mxC)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

#include <iostream>
#include <vector>

using namespace std;

int mxC = 1e7;
vector<int> d(mxC + 1), min_n(mxC + 1, -1);

int main() {
	// preprocess
	for (int i = 1; i <= mxC; i++)
		for (int j = i; j <= mxC; j += i)
			d[j] += i;
	for (int i = mxC; i > 0; i--)
		if (d[i] <= mxC)
			min_n[d[i]] = i;
	
	int t;
	cin >> t;
	while (t--) {
		int c;
		cin >> c;
		cout << min_n[c] << endl;
	}
	
	return 0;
}