// Problem Code: 112A
 
#include <iostream>
#include <string>
#include <algorithm>
 
using namespace std;

int petya_and_strings(string& s1, string& s2) {
	transform(s1.begin(), s1.end(), s1.begin(), [](char& c) { return tolower(c); });
	transform(s2.begin(), s2.end(), s2.begin(), [](char& c) { return tolower(c); });
	return s1.compare(s2);
}

int main() {
	string s1, s2;
	cin >> s1 >> s2;
	cout << petya_and_strings(s1, s2);
	return 0;
}