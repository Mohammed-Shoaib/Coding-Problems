// Problem Code: 1114A

#include <iostream>

using namespace std;

string gotAnyGrapes(int x, int y, int z, int a, int b, int c) {
	if (x > a)
		return "NO";
	else if (y > a + b - x)
		return "NO";
	else if (z > a + b + c - x - y)
		return "NO";
	else
		return "YES";
}

int main() {
	int x, y, z, a, b, c;
	cin >> x >> y >> z >> a >> b >> c;
	cout << gotAnyGrapes(x, y, z, a, b, c);
	return 0;
}