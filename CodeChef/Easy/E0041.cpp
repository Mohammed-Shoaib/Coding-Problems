// Problem Code: PLZLYKME

#include <iostream>

using namespace std;

string pleaseLikeMe(int L, int D, int S, int C) {
	long likes = S;
	for(int i=1 ; i<=D ; i++) {
		if(likes >= L)
			return "ALIVE AND KICKING";
		likes += likes*C;
	}
	return "DEAD AND ROTTING";
}

int main() {
	int T, L, D, S, C;
	cin >> T;
	while(T--) {
		cin >> L >> D >> S >> C;
		cout << pleaseLikeMe(L, D, S, C) << endl;
	}
	return 0;
}