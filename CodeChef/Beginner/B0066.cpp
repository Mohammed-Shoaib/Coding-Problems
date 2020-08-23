// Problem Code: CANDY123

#include <iostream>
#include <cmath>

using namespace std;

string winner(int A, int B) {
	int limak, bob;
	limak = sqrt(A);
	bob = (-1 + sqrt(1+4*B))/2;
	return (limak > bob) ? "Limak" : "Bob";
}

int main() {
	int T, A, B;
	cin >> T;
	while(T--) {
		cin >> A >> B;
		cout << winner(A, B) << endl;
	}
	return 0;
}