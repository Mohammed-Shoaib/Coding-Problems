/*
Problem Statement: https://www.hackerrank.com/challenges/30-exceptions-string-to-integer/problem
*/

#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

void convert(string& s) {
	try {
		cout << stoi(s) << endl;
	} catch(invalid_argument& e) {
		cout << "Bad String" << endl;
	}
}

int main() {
	string s;
	cin >> s;
	convert(s);
	return 0;
}