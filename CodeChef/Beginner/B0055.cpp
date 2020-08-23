// Problem Code: FRGTNLNG

#include <iostream>

using namespace std;

int goodJoke(int N) {
	int result = 1;
	for(int i=2 ; i<=N ; i++)
		result ^= i;
	return result;
}

int main() {
	int T, N, x, y;
	cin >> T;
	while(T--) {
		cin >> N;
		for(int i=0 ; i<N ; i++)
			cin >> x >> y;
		cout << goodJoke(N) << endl;
	}
	return 0;
}