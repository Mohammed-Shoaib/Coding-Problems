#include <iostream>
#include <string>

using namespace std;

bool is_roaring(int Y) {
	string y = to_string(Y);
	
	for (int i = 1; i <= y.length() / 2; i++) {
		string z = y.substr(0, i);
		int val = stoi(z);
		while (z.length() < y.length())
			z += to_string(++val);
		if (y == z)
			return true;
	}
	
	return false;
}

int roaring_years(int Y) {
	while (!is_roaring(++Y));
	return Y;
}

int main() {
	int T;
	cin >> T;
	for (int x = 1; x <= T; x++) {
		int Y;
		cin >> Y;
		cout << "Case #" << x << ": " << roaring_years(Y) << endl;
	}
	return 0;
}