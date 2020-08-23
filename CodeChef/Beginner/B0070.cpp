// Problem Code: CATSDOGS

#include <iostream>
#include <cmath>

using namespace std;

string catsAndDogs(int C, int D, int L) {
	long lower, upper;
	if(L % 4)
		return "no";
	lower = (long)4*(max(0, C-2*D) + D);
	upper = (long)4*(C+D);
	return (lower <= L && L <= upper) ? "yes" : "no";
}

int main() {
	int T, C, D, L;
	cin >> T;
	while(T--) {
		cin >> C >> D >> L;
		cout << catsAndDogs(C, D, L) << endl;
	}
	return 0;
}