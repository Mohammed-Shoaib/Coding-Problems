// Problem Code: 656F

#include <iostream>
#include <string>

using namespace std;

int ace_it(string& s) {
	int sum = 1;
	for (int i = 1; i < s.length(); i++) {
		if (s[i] == '1')
			sum += 10;
		else
			sum += s[i] - '0';
	}
	return sum;
}

int main() {
	string s;
	cin >> s;
	cout << ace_it(s);
	return 0;
}