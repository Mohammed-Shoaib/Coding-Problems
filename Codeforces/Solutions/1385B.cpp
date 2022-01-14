// Problem Code: 1385B
 
#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<int> restore_the_permutation_by_merger(int n, vector<int>& a) {
	vector<int> p;
	set<int> seen;
	
	for (int& x: a)
		if (seen.insert(x).second)
			p.push_back(x);
	
	return p;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n << 1);
		for (int& x: a)
			cin >> x;
		vector<int> p = restore_the_permutation_by_merger(n << 1, a);
		for (int i = 0; i < n; i++)
			cout << p[i] << " ";
		cout << endl;
	}
	return 0;
}
