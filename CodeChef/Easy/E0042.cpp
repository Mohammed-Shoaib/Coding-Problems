// Problem Code: ANUWTA

#include <iostream>

using namespace std;

long walkOnTheAxis(int N) {
	return (long)N*(N+1)/2 + N;
}

int main() {
	int T, N;
	cin >> T;
	while(T--) {
		cin >> N;
		cout << walkOnTheAxis(N) << endl;
	}
	return 0;
}