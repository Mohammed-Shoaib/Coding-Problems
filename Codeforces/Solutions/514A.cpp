// Problem Code: 514A

#include <iostream>
#include <string>

using namespace std;

string invert(string& x) {
	for (int i = 0; i < x.length(); i++) {
		if (i == 0 && x[i] == '9')
			continue;
		else if (x[i] > '4')
			x[i] = '9' - x[i] + '0';
	}
	return x;
}

int main() {
	string x;
	cin >> x;
	cout << invert(x);
	return 0;
}