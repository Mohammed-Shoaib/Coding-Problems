// Problem Code: FLOW016

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int T, A, B, gcd;
	long lcm;
	cin >> T;
	for(int i=1 ; i<=T ; i++){
		cin >> A >> B;
		gcd = __gcd(A, B);
		lcm = long(A)*B/gcd;
		cout << gcd << " " << lcm << endl;
	}
	return 0;
}