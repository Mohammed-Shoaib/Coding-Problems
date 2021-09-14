// Problem Code: 1271A

#include <iostream>
#include <algorithm>

using namespace std;

int suits(int a, int b, int c, int d, int e, int f) {
	int type_1, type_2, profit;
	type_1 = min(a, d);
	type_2 = min(min(b, c), d);
	if (e > f)
		type_2 = min(d - type_1, type_2);
	else
		type_1 = min(d - type_2, type_1);
	return type_1 * e + type_2 * f;
}

int main() {
	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
	cout << suits(a, b, c, d, e, f);
	return 0;
}