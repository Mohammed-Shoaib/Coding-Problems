// Problem Code: abc158_a

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string station_and_bus(string& S) {
	sort(S.begin(), S.end());
	return (S.front() != S.back()) ? "Yes" : "No";
}

int main() {
	string S;
	cin >> S;
	cout << station_and_bus(S);
	return 0;
}