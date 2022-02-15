// Problem Code: 236A
 
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string boy_or_girl(string s) {
	vector<bool> is_set(26);
	
	for (char& c: s)
		is_set[c - 'a'] = true;
	bool is_odd = count(is_set.begin(), is_set.end(), true) & 1;
	
	if (is_odd)
		return "IGNORE HIM!";
	else
		return "CHAT WITH HER!";
}

int main() {
	string s;
	cin >> s;
	cout << boy_or_girl(s);
	return 0;
}