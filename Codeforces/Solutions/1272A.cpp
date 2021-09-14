// Problem Code: 1272A

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int three_friends(vector<int>& a) {
	sort(a.begin(), a.end());
	if (a[0] != a[2])
		a[2]--;
	if (a[0] != a[2])
		a[0]++;
	return 2 * (a[2] - a[0]);
}

int main() {
	int q;
	cin >> q;
	while (q--) {
		vector<int> a(3);
		for (int i = 0; i < a.size(); i++)
			cin >> a[i];
		cout << three_friends(a) << endl;
	}	
	return 0;
}