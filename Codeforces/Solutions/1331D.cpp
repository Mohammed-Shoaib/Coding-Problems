// Problem Code: 1331D

#include <iostream>
#include <string>

using namespace std;

int again(string& s) {
	return (s.back() - '0') & 1;
}

int main() {
	string s;
	cin >> s;
	cout << again(s);
	return 0;
}