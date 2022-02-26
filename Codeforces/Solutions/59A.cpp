// Problem Code: 59A
 
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string word(string s) {
	int upper_cnt = 0;
	
	for (char& c: s)
		upper_cnt += isupper(c) != 0;
	
	if (upper_cnt > s.length() / 2)
		transform(s.begin(), s.end(), s.begin(), ::toupper);
	else
		transform(s.begin(), s.end(), s.begin(), ::tolower);
	
	return s;
}

int main() {
	string s;
	cin >> s;
	cout << word(s);
	return 0;
}