// Problem Code: 32B
 
#include <iostream>
#include <string>

using namespace std;

string borze(string& s) {
	string t;
	
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '.')
			t += '0';
		else {
			i++;
			if (s[i] == '.')
				t += '1';
			else
				t += '2';
		}
	}
	
	return t;
}

int main() {
	string s;
	cin >> s;
	cout << borze(s);
	return 0;
}
