// Problem Code: DECINC

#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N;
	if(N % 4)
		cout << N-1;
	else
		cout << N+1;
	return 0;
}