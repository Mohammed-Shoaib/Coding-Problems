// Problem Code: 281A
 
#include <iostream>
#include <string>

using namespace std;

string word_capitalization(string s) {
	s[0] = toupper(s[0]);
	return s;
}

int main() {
	string s;
	cin >> s;
	cout << word_capitalization(s);
	return 0;
}