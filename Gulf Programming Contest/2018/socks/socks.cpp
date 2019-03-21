#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

bool possible(vector<int> &colors) {
	for (int i = 0; i < colors.size(); i++)
		if (colors[i] > 1)
			return true;
	return false;
}

string socks(int C, vector<int> &colors) {
	return (possible(colors)) ? to_string(C + 1) : "Impossible";
}

int main() {
	freopen("socks.in", "r", stdin);
	freopen("output.out", "w", stdout);
	
	int T, k = 1;
	cin >> T;
	while (T--) {
		int C;
		cin >> C;
		vector<int> colors(C);
		for (int i = 0; i < C; i++)
			cin >> colors[i];
		cout << k << ". " << socks(C, colors) << endl;
		k++;
	}
	
	return 0;
}