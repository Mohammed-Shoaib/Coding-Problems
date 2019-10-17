/*
Problem Code: https://www.hackerrank.com/challenges/prettyprint/problem
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int T; cin >> T;
	cout << setiosflags(ios::uppercase);
	cout << setw(0xf) << internal;
	while(T--) {
		double A; cin >> A;
		double B; cin >> B;
		double C; cin >> C;
        cout << left << hex << showbase << nouppercase << (long long)A << endl;
        cout << setw(15) << setfill('_') << right << showpos << fixed << setprecision(2) << B << '\n';
        cout << noshowpos << scientific << uppercase << setprecision(9) << C << endl;
	}
	return 0;

}