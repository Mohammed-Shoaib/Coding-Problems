#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

int digits(string N) {
	int length = 0;
	vector<string> s = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
	for (int i = 0; i < N.length(); i++)
		length += s[N[i] - '0'].length();
	return length;
}

int main() {
	freopen("digits.in", "r", stdin);
	freopen("output.out", "w", stdout);
	int T, k = 1;
	cin >> T;
	while (T--) {
		string N;
		cin >> N;
		cout << k << ". " << digits(N) << endl;
		k++;
	}
	return 0;
}