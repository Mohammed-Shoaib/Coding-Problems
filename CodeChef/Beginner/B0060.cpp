// Problem Code: CFRTEST

#include <iostream>
#include <vector>
#include <set>

using namespace std;

int devuAndFriendship(vector<int> d) {
	int duplicates = d.size() - set<int>(d.begin(), d.end()).size();
	return d.size() - duplicates;
}

int main() {
	int T, n, num;
	vector<int> d;
	cin >> T;
	while(T--) {
		cin >> n;
		for(int i=0 ; i<n ; i++) {
			cin >> num;
			d.push_back(num);
		}
		cout << devuAndFriendship(d) << endl;
		d.clear();
	}
	return 0;
}