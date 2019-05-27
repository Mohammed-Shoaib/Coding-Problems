// Problem Code: ANKTRAIN

#include <iostream>
#include <string>

using namespace std;

string trainPartner(int N) {
	int B[] = {-1, 4, 5, 6, 1, 2, 3, 8};
	string partner[] = {"SL", "LB", "MB", "UB", "LB", "MB", "UB", "SU"};
	return to_string(N - (N % 8) + B[N % 8]) + partner[N % 8];
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		cout << trainPartner(N) << endl;
	}
    return 0;
}