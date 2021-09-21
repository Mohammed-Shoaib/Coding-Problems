// Problem Code: 1333A

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void little_artem(int n, int m) {
	vector<string> grid(n, string(m, 'B'));
	grid[0][0] = 'W';
	for (int i = 0; i < n; i++)
		cout << grid[i] << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		little_artem(n, m);
	}
	return 0;
}