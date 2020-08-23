// Problem Code: NUMGAME2

#include <iostream>

using namespace std;

string winner(int N){
	return ((N-1) % 4) ? "BOB" : "ALICE";
}

int main()
{
	int T, N;
	cin >> T;
	while(T--){
		cin >> N;
		cout << winner(N) << endl;
	}
	return 0;
}