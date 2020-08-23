// Problem Code: TWOVSTEN

#include <iostream>

using namespace std;

int twoVsTen(int X) {
	if(X % 10 == 0)
		return 0;
	else if(X % 5 == 0)
		return 1;
	else
		return -1;
}

int main() {
	int T, X;
	cin >> T;
	while(T--) {
		cin >> X;
		cout << twoVsTen(X) << endl;
	}
	return 0;
}