// Problem Code: 520A
 
#include <iostream>
#include <string>
#include <set>

using namespace std;

string pangram(string& s) {
	set<char> seen;
	for (char& c: s) {
		seen.insert(tolower(c));
		if (seen.size() == 26)
			return "YES";
	}
	return "NO";
}

int main() {
	int n;
	string s;
	cin >> n >> s;
	cout << pangram(s);
	return 0;
}