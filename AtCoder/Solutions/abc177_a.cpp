// Problem Code: abc177_a

#include <iostream>
#include <string>

using namespace std;

string dont_be_late(int D, int T, int S) {
	return (D <= S * T) ? "Yes" : "No";
}

int main() {
	int D, T, S;
	cin >> D >> T >> S;
	cout << dont_be_late(D, T, S);
	return 0;
}