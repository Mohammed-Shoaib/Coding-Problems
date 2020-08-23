// Problem Code: FLOW013

#include <iostream>

using namespace std;

string validTriangles(int A, int B, int C){
	return (A+B+C == 180) ? "YES" : "NO";
}

int main()
{
	int T, A, B, C;
	cin >> T;
	for(int i=1 ; i<=T ; i++){
		cin >> A >> B >> C;
		cout << validTriangles(A, B, C) << endl;
	}
	return 0;
}