#include <iostream>
#include <cstdio>

using namespace std;

int diapers(int D, int B) {
	return D / B;
}

int main() {
	freopen("diapers.in", "r", stdin);
	freopen("output.out", "w", stdout);

	int T, k = 1;
	cin >> T;
	while (T--) {
		int D, B;
		cin >> D >> B;
		cout << k << ". " << diapers(D, B) << endl;
		k++;
	}

	return 0;
}