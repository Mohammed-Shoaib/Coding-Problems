#include <iostream>

using namespace std;

void number_guessing(int A, int B) {
	string verdict;
	
	// binary search
	while (A <= B) {
		int q = A + (B - A + 1) / 2;
		cout << q << endl;
		cin >> verdict;
		
		if (verdict == "CORRECT")
			return;
		else if (verdict == "TOO_SMALL")
			A = q;
		else
			B = q - 1;
	}
}

int main() {
	int T;
	cin >> T;
	for (int x = 1; x <= T; x++) {
		int A, B, N;
		cin >> A >> B >> N;
		number_guessing(A, B);
	}
	return 0;
}