// Problem Code: 41A
 
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string translation(string s, string t) {
	return equal(s.begin(), s.end(), t.rbegin(), t.rend()) ? "YES" : "NO";
}

int main() {
	string s, t;
	cin >> s >> t;
	cout << translation(s, t);
	return 0;
}