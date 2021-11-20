// Problem Code: 1281C
 
#include <iostream>
#include <string>
#include <deque>
 
using namespace std;
 
int cut_and_paste(int x, string& s) {
	int len, mod, n;
	long long paste;
	deque<char> d(s.begin(), s.end());
 
	len = s.length();
	mod = 1e9 + 7;
 
	for (int i = 1; i <= x; i++) {
		paste = d[0] - '0';
		d.pop_front();
		len = (i + (len - i + mod) * paste) % mod;
		n = d.size();
		for (int j = 1; j < paste && d.size() < x; j++)
			for (int k = 0; k < n; k++)
				d.push_back(d[k]);
	}
 
	return len;
}
 
int main() {
	int t;
	cin >> t;
	while (t--) {
		int x;
		string s;
		cin >> x >> s;
		cout << cut_and_paste(x, s) << endl;
	}
	return 0;
}