/*
Problem Statement: https://www.hackerrank.com/challenges/30-conditional-statements/problem
*/

#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;

	if (n % 2 == 0 && (n < 6 || n > 20))
		cout << "Not ";
	cout << "Weird";
	
	return 0;
}