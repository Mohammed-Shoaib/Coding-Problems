// Problem Code: 1343C
 
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

bool same_sign(int x, int y) {
	return (x > 0) == (y > 0);
}

int64_t alternating_subsequences(int n, vector<int>& a) {
	vector<int> b = { a[0] };
	
	for (int& x: a) {
		if (!same_sign(x, b.back()))
			b.push_back(x);
		else
			b.back() = max(x, b.back());
	}
	
	return accumulate(b.begin(), b.end(), static_cast<int64_t>(0));
}

int main() {
	int t;
	cin >> t;
	
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		
		for (int& x: a)
			cin >> x;
		
		cout << alternating_subsequences(n, a) << endl;
	}
	
	return 0;
}
