// Problem Code: DIFFSUM

#include <iostream>

using namespace std;

int sumOrDifference(int N1, int N2) {
	return (N1 > N2) ? (N1 - N2) : (N1 + N2);
}

int main() {
	int N1, N2;
	cin >> N1 >> N2;
	cout << sumOrDifference(N1, N2);
	return 0;
}