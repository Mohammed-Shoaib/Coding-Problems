// Problem Code: 1265A

#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

char update(char l, char r) {
	unordered_set<char> set = {'a', 'b', 'c'};
	set.erase(l);
	set.erase(r);
	return *set.begin();
}

string construct(string& s) {
	int n = s.length();
	
	// Base Cases
	if (n == 1)
		return (s[0] == '?') ? "a" : s;
	if (s[0] == '?')
		s[0] = update('?', s[1]);
	if (s[n - 1] == '?')
		s[n - 1] = update(s[n - 2], '?');
	if (s[0] == s[1])
		return "-1";
	
	// Construct beautiful string
	for (int i = 1; i < n - 1; i++) {
		if (s[i] == '?')
			s[i] = update(s[i - 1], s[i + 1]);
		else if (s[i] == s[i + 1])
			return "-1";
	}
	
	return s;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		cout << construct(s) << endl;
	}
	return 0;
}