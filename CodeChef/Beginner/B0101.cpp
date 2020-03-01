// Problem Code: MATCHES

#include <iostream>

using namespace std;

int playing_with_matches(int A, int B) {
	int matches = 0, sum = A + B;
	int count[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
	while (sum != 0) {
		matches += count[sum % 10];
		sum /= 10;
	}
	return matches;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int A, B;
		cin >> A >> B;
		cout << playing_with_matches(A, B) << endl;
	}
	return 0;
}