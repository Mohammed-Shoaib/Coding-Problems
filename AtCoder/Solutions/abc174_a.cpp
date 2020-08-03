// Problem Code: abc174_a

#include <iostream>
#include <string>

using namespace std;

string air_conditioner(int X) {
	return (X >= 30) ? "Yes" : "No";
}

int main() {
	int X;
	cin >> X;
	cout << air_conditioner(X);
	return 0;
}