// Problem Code: abc162_a

#include <iostream>
#include <string>

using namespace std;

string lucky_7(int N) {
	while (N) {
		if (N % 10 == 7)
			return "Yes";
		N /= 10;
	}
	return "No";
}

int main() {
	int N;
	cin >> N;
	cout << lucky_7(N);
	return 0;
}