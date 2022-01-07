// Problem Code: 1360B
 
#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

int honest_coach(int n, vector<int>& s) {
	int diff = numeric_limits<int>::max();
	sort(s.begin(), s.end());
	
	for (int i = 1; i < n; i++)
		diff = min(s[i] - s[i - 1], diff);
	
	return diff;
}

int main() {
	int t;
	cin >> t;
	
	while (t--) {
		int n;
		cin >> n;
		vector<int> s(n);
		
		for (int i = 0; i < n; i++)
			cin >> s[i];
		
		cout << honest_coach(n, s) << endl;
	}
	
	return 0;
}