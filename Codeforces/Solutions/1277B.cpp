// Problem Code: 1277B

#include <iostream>
#include <vector>
#include <set>
#include <functional>

using namespace std;

int make_odd(int n, vector<int>& a) {
	int moves = 0;
	set<int, greater<int>> seen(a.begin(), a.end());

	for(auto num: seen)
		if (num % 2 == 0) {
			moves++;
			seen.insert(num / 2);
		}
	
	return moves;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		cout << make_odd(n, a) << endl;
	}
	return 0;
}