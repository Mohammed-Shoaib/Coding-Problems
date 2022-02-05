// Problem Code: 208A
 
#include <iostream>
#include <string>
#include <utility>

using namespace std;

string dubstep(string s) {
	string t;
	int n = s.length();
	bool new_word = false;
	
	for (int i = 0; i < n; i++) {
		if (i + 2 < n && s[i] == 'W' && s[i + 1] == 'U' && s[i + 2] == 'B') {
			i += 2;
			new_word = true;
		} else {
			if (exchange(new_word, false) && !t.empty())
				t += " ";
			t += s[i];
		}
	}
	
	return t;
}

int main() {
	string s;
	cin >> s;
	cout << dubstep(s);
	return 0;
}