// Problem Code: 118A
 
#include <iostream>
#include <cctype>
#include <string>
#include <vector>
 
using namespace std;

bool vowel(char& c) {
	vector<char> vowels = {'a', 'o', 'y', 'e', 'u', 'i'};
	for (char& vowel: vowels)
		if (c == vowel)
			return true;
	return false;
}
 
string string_task(string& s) {
	string t;
	for (char c: s) {
		c = tolower(c);
		if (vowel(c))
			continue;
		t += '.';
		t += c;
	}
	return t;
}
 
int main() {
	string s;
	cin >> s;
	cout << string_task(s);
	return 0;
}