// Problem Code: 1331B

#include <iostream>
#include <string>

using namespace std;

string limericks(int a) {
	int f = 2;
	while (a % f)
		f++;
	return to_string(f) + to_string(a / f);
}

int main() {
	int a;
	cin >> a;
	cout << limericks(a);
	return 0;
}