// Problem Code: 339A
 
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

string helpful_maths(string& s) {
	string digit;
	vector<char> digits;
	istringstream ss(s);
	
	while (getline(ss, digit, '+'))
		digits.push_back(digit.at(0));
	sort(digits.begin(), digits.end());
	
	string t(1, digits[0]);
	for (int i = 1; i < digits.size(); i++) {
		t += '+';
		t += digits[i];
	}
	
	return t;
}

int main() {
	string s;
	cin >> s;
	cout << helpful_maths(s);
	return 0;
}