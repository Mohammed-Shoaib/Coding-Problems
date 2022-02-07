// Problem Code: 230A
 
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

string dragons(int s, int n, vector<pair<int, int>>& d) {
	sort(d.begin(), d.end());
	
	for (int i = 0; i < n; i++) {
		if (s <= d[i].first)
			return "NO";
		s += d[i].second;
	}
	
	return "YES";
}

int main() {
	int s, n;
	cin >> s >> n;
	vector<pair<int, int>> d(n);
	for (int i = 0; i < n; i++)
		cin >> d[i].first >> d[i].second;
	cout << dragons(s, n, d);
	return 0;
}