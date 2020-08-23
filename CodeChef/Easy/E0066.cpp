// Problem Code: COMPILER

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int compilersAndParsers(string L) {
	int len;
	stack<char> s;
	len = 0;
	for (int i = 0 ; i < L.length() ; i++) {
		if (L[i] == '<')
			s.push(L[i]);
		else {
			if (s.empty())
				break;
			s.pop();
		}
		if (s.empty())
			len = i + 1;
	}
	return len;
}

int main() {
	int T;
	string L;
	cin >> T;
	while (T--) {
		cin >> L;
		cout << compilersAndParsers(L) << endl;
	}
	return 0;
}