// Problem Code: 1281A

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

string suffix_three(string& s) {
	int n = s.length();
	unordered_map<char, string> map = {
		{'o', "FILIPINO"},
		{'u', "JAPANESE"},
		{'a', "KOREAN"}
	};
	return map[s[n - 1]];
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		cout << suffix_three(s) << endl;
	}
	return 0;
}