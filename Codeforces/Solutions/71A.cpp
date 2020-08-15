// Problem Code: 71A

#include <iostream>
#include <string>

using namespace std;

string way_too_long_words(string& s) {
	int n = s.length();
	if (n <= 10)
		return s;
	else
		return s[0] + to_string(n - 2) + s[n - 1];
}

int main() {
	int n;
	cin >> n;
	while (n--) {
		string s;
		cin >> s;
		cout << way_too_long_words(s) << endl;
	}
	return 0;
}