// Problem Code: 1269C

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void fill(string& s, string& d) {
	int k = d.length();
	for (int i = 0; i < s.length(); i++)
		s[i] = d[i % k];
}

void beautiful_integer(int n, int k, string& s) {
	int i;
	string d(s.begin(), s.begin() + k), copy = s;
	
	fill(s, d);
	if (s >= copy)
		return;
	
	for (i = k - 1; i >= 0; i--)
		if (d[i] != '9') {
			d[i]++;
			fill(d.begin() + i + 1, d.end(), '0');
			break;
		}
	fill(s, d);
}

int main() {
	int n, k;
	string s;
	cin >> n >> k >> s;
	beautiful_integer(n, k, s);
	cout << n << endl;
	cout << s << endl;
	return 0;
}