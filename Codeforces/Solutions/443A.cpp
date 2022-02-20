// Problem Code: 443A
 
#include <iostream>
#include <string>
#include <set>

using namespace std;

int anton_and_letters(string s) {
	set<char> seen;
	for (int i = 1; i + 1 < s.length(); i += 3)
		seen.insert(s[i]);
	return seen.size();
}

int main() {
	string s;
	getline(cin, s);
	cout << anton_and_letters(s);
	return 0;
}