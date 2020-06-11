// Problem Code: 4A

#include <iostream>
#include <string>

using namespace std;

string watermelon(int w) {
	return (w & 1 || w <= 2) ? "NO" : "YES";
}

int main() {
	int w;
	cin >> w;
	cout << watermelon(w);
	return 0;
}