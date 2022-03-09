// Problem Code: 368B
 
#include <iostream>
#include <vector>
#include <set>

using namespace std;

void sereja_and_suffixes(int n, vector<int>& a, vector<int>& q) {
	set<int> seen;
	
	for (int i = n - 1; i >= 0; i--) {
		seen.insert(a[i]);
		q[i] = seen.size();
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n), q(n);
	
	for (int& x: a)
		cin >> x;
	
	sereja_and_suffixes(n, a, q);
	
	while (m--) {
		int l;
		cin >> l;
		cout << q[l - 1] << endl;
	}
	
	return 0;
}
