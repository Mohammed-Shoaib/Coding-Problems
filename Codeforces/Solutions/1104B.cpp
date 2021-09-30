// Problem Code: 1104B

#include <iostream>
#include <string>
#include <stack>

using namespace std;

string gameWithString(string S) {
	int pairs = 0;
	stack<char> s;
	for (int i = 0; i < S.length(); i++) {
		if (!s.empty() && s.top() == S[i]) {
			s.pop();
			pairs++;
		}
		else
			s.push(S[i]);
	}
	return (pairs & 1) ? "Yes" : "No";
}

int main() {
	string S;
	cin >> S;
	cout << gameWithString(S) << endl;
	return 0;
}