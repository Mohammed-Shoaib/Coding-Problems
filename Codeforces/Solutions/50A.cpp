// Problem Code: 50A
 
#include <iostream>
 
using namespace std;

int domino_piling(int M, int N) {
	return (M * N) / 2;
}

int main() {
	int M, N;
	cin >> M >> N;
	cout << domino_piling(M, N);
	return 0;
}