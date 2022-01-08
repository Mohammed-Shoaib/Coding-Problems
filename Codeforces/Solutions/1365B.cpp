// Problem Code: 1365B
 
#include <iostream>
#include <vector>
#include <set>

using namespace std;

string trouble_sort(int n, vector<int>& a, vector<int>& b) {
	bool sorted = true;
	set<int> types = {b[0]};
	
	for (int i = 1; i < n; i++) {
		types.insert(b[i]);
		sorted &= a[i - 1] <= a[i];
	}
	
	if (!sorted && types.size() == 1)
		return "No";
	return "Yes";
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n), b(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		for (int i = 0; i < n; i++)
			cin >> b[i];
		cout << trouble_sort(n, a, b) << endl;
	}
	return 0;
}