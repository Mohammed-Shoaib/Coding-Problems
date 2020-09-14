// Problem Code: abc176_b

#include <iostream>
#include <string>

using namespace std;

string is_multiple(string N) {
	int sum = 0;
	for (char& c: N)
		sum += c - '0';
	return (sum % 9 == 0) ? "Yes" : "No";
}

int main() {
	string N;
	cin >> N;
	cout << is_multiple(N);
	return 0;
}