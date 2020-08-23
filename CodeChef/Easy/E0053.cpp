// Problem Code: J7

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double theBestBox(int P, int S) {
	double a, b, V;
	a = (P - sqrt(pow(P, 2) - 24*S))/12.0;
	b = (P/4.0 - 2*a);
	V = pow(a, 2) * b;
	return V;
}

int main(){
	int T, P, S;
	cout << fixed << setprecision(2);
	cin >> T;
	while(T--) {
		cin >> P >> S;
		cout << theBestBox(P, S) << endl;
	}
	return 0;
}