// Problem Code: 705A
 
#include <iostream>
#include <string>

using namespace std;

string hulk(int n) {
	string s;
	for (int i = 1; i <= n; i++) {
		if (i > 1)
			s += "that ";
		s += (i & 1) ? "I hate " : "I love ";
	}
	s += "it";
	return s;
}

int main() {
	int n;
	cin >> n;
	cout << hulk(n);
	return 0;
}