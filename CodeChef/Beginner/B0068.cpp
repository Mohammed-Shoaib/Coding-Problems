// Problem Code: BRACKETS

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string brackets(string A) {
	int balance, maxBalance;
	balance = maxBalance = 0;
	for(int i=0 ; i<A.length() ; i++) {
		(A[i] == '(') ? balance++ : balance--;
		if(balance > maxBalance)
			maxBalance = balance;
	}
	string B = string(maxBalance, '(') + string(maxBalance, ')');
	return B;
}

int main() {
	int T;
	string A;
	cin >> T;
	while(T--) {
		cin >> A;
		cout << brackets(A) << endl;
	}
	return 0;
}