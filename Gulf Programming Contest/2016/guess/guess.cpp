#include <iostream>
#include <cstdio>
#include <iomanip>
#include <cmath>

using namespace std;

double guess(long long N, long long X, long long Y) {
	double prob;
	N -= X;
	prob = (Y * 100) / pow(10, N);
	return (prob > 100) ? 100 : prob;
}

int main() {
	freopen("guess.in", "r", stdin);
	freopen("output.out", "w", stdout);
	cout << setprecision(2) << fixed;
	
	int T, k;
	k = 1;
	cin >> T;
	while (T--) {
		int N, X, Y;
		cin >> N >> X >> Y;
		cout << k << ". " << guess(N, X, Y) << "%" << endl;
		k++;
	}

	return 0;
}
