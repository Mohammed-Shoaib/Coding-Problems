// Problem Code: MARCHA2

#include <iostream>
#include <vector>

using namespace std;

string johnnyAndTheBeanstalk(vector<int> &l) {
	long long rem = 1;
	for (int i = 0; i < l.size(); rem *= 2, i++) {
		rem -= l[i];
		if (rem < 0)
			return "No";
	}
	return rem ? "No" : "Yes";
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int k;
		cin >> k;
		vector<int> l(k);
		for (int i = 0; i < k; i++)
			cin >> l[i];
		cout << johnnyAndTheBeanstalk(l) << endl;
	}
	return 0;
}