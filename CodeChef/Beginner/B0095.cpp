// Problem Code: AREAPERI

#include <iostream>

using namespace std;

void areaOrPerimeter(int L, int B) {
	int area, peri;
	area = L * B;
	peri = 2 * (L + B);
	if (area > peri) {
		cout << "Area" << endl;
		cout << area << endl;
	} else if (peri > area) {
		cout << "Peri" << endl;
		cout << peri << endl;
	} else {
		cout << "Eq" << endl;
		cout << area << endl;
	}
	return;
}

int main() {
	int L, B;
	cin >> L >> B;
	areaOrPerimeter(L, B);
	return 0;
}