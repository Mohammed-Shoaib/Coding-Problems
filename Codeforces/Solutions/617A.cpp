// Problem Code: 617A
 
#include <iostream>

using namespace std;

int elephant(int x) {
	return (x + 5 - 1) / 5;
}

int main() {
	int x;
	cin >> x;
	cout << elephant(x);
	return 0;
}