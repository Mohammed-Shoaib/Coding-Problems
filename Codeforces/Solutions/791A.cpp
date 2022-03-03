// Problem Code: 791A
 
#include <iostream>

using namespace std;

int bear_and_big_brother(int a, int b) {
	int years = 0;
	while (a <= b) {
		years++;
		a *= 3;
		b *= 2;
	}
	return years;
}

int main() {
	int a, b;
	cin >> a >> b;
	cout << bear_and_big_brother(a, b);
	return 0;
}