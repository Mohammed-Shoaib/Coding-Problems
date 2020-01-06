// Problem Code: TWOGRS

#include <iostream>

using namespace std;

string two_groups(int A, int B, int C) {
	int sum = A + 2 * B + 3 * C;
	if (sum & 1)
		return "NO";
	else if (A == 0 && C == 0)
		return (B & 1) ? "NO" : "YES";
	else if (A == 1 && B == 0)
		return "NO";
	else if (A == 0 && B == 1)
		return "NO";
	else
		return "YES";
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int A, B, C;
		cin >> A >> B >> C;
		cout << two_groups(A, B, C) << endl;
	}
	return 0;
}