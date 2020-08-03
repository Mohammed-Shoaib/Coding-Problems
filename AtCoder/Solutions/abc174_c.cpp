// Problem Code: abc174_c

#include <iostream>

using namespace std;

int repsept(int K) {
	int num = 0;
	for (int i = 1; i <= K; i++) {
		num = (10 * num + 7) % K;
		if (num == 0)
			return i;
	}
	return -1;
}

int main() {
	int K;
	cin >> K;
	cout << repsept(K);
	return 0;
}