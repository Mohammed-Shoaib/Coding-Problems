/*
Problem Statement: https://www.hackerrank.com/challenges/30-review-loop/problem
*/

#include <iostream>

using namespace std;

void odd_even(string& S) {
	string odd, even;
	odd = even = "";
	for (int i = 0; i < S.length(); i++) {
		if (i & 1)
			odd += S[i];
		else
			even += S[i];
	}
	cout << even << " " << odd << endl;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		string S;
		cin >> S;
		odd_even(S);
	}
	return 0;
}