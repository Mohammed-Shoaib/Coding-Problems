// Problem Code: 61A
 
#include <iostream>
#include <string>

using namespace std;

string ultra_fast_mathematician(string s, string t) {
	string ans;
	for (int i = 0; i < s.length(); i++)
		ans += (s[i] ^ t[i]) + '0';
	return ans;
}

int main() {
	string s, t;
	cin >> s >> t;
	cout << ultra_fast_mathematician(s, t);
	return 0;
}