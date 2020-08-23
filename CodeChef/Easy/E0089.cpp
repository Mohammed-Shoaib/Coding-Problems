// Problem Code: KOL15A

#include <iostream>
#include <string>

using namespace std;

int processingAString(string &S) {
	int sum = 0;
	for (char c: S)
		if (isdigit(c))
			sum += c - '0';
	return sum;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		string S;
		cin >> S;
		cout << processingAString(S) << endl;
	}
	return 0;
}