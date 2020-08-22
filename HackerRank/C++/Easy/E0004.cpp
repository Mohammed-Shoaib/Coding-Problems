/*
Problem Statement: https://www.hackerrank.com/challenges/c-tutorial-conditional-if-else/problem
*/

#include <iostream>
#include <string>

using namespace std;

int main() {
	string nos [] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	int n;
	cin >> n;
	if (n <= 9)
		cout << nos[n];
	else
		cout << "Greater than 9";
	return 0;
}