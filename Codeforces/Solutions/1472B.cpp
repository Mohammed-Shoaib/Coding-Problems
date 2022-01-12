// Problem Code: 1472B
 
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string fair_division(int n, vector<int>& a) {
	int ones, twos;
	ones = count(a.begin(), a.end(), 1);
	twos = count(a.begin(), a.end(), 2);
	return ((ones & 1) || ((twos & 1) && ones == 0)) ? "NO" : "YES";
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
		cout << fair_division(n, a) << endl;
	}
	return 0;
}
