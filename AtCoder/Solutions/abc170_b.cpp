// Problem Code: abc170_b

#include <iostream>
#include <string>

using namespace std;

string crane_and_turtle(int x, int y) {
	for (int j, i = 0; i <= x; i++) {
		j = x - i;
		if (i * 2 + j * 4 == y)
			return "Yes";
	}
	return "No";
}

int main() {
	int x, y;
	cin >> x >> y;
	cout << crane_and_turtle(x, y);
	return 0;
}