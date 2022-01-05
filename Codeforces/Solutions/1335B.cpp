// Problem Code: 1335B

#include <iostream>
#include <string>

using namespace std;

string construct(int n, int a, int b) {
	string s;
	for (int i = 0; i < n; i++)
		s += 'a' + i % b;
	return s;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, a, b;
		cin >> n >> a >> b;
		cout << construct(n, a, b) << endl;
	}
	return 0;
}