// Problem Code: 489C
 
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void construct(int m, int s) {
	string min_s, max_s;
	int min_v = 9 * m - s, max_v = s;
	
	if (m == 1 && s == 0) {
		cout << "0 0" << endl;
		return;
	} else if (s == 0 || s > 9 * m) {
		cout << "-1 -1" << endl;
		return;
	}
	
	for (int i = 0; i < m; i++) {
		int x = min(9 - (i == 0), min_v);
		min_v -= x;
		min_s += '9' - x;
		
		x = min(9, max_v);
		max_v -= x;
		max_s += '0' + x;
	}
	
	cout << min_s << " " << max_s << endl;
}

int main() {
	int m, s;
	cin >> m >> s;
	construct(m, s);
	return 0;
}