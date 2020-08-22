/*
Problem Statement: https://www.hackerrank.com/challenges/c-tutorial-stringstream/problem
*/

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
	string s, token;
	cin >> s;
	istringstream ss(s);
	while (getline(ss, token, ','))
		cout << token << endl;
	return 0;
}