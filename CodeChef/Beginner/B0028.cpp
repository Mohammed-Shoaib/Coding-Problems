// Problem Code: TRISQ

#include <iostream>

using namespace std;

int totalSquares(int B){
	int n = B/2 - 1;
	return n*(n+1)/2;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T, B;
	cin >> T;
	for(int i=1 ; i<=T ; i++){
		cin >> B;
		cout << totalSquares(B) << endl;
	}
	return 0;
}