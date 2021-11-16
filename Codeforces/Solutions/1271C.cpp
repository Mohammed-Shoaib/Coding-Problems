// Problem Code: 1271C

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void shawarma_tent(int n, int sx, int sy, vector<int>& x, vector<int>& y) {
	int c, px, py;
	vector<int> pos(4);
	
	for (int i = 0; i < n; i++) {
		if (y[i] < sy)
			pos[0]++;
		else if (y[i] > sy)
			pos[1]++;
		if (x[i] < sx)
			pos[2]++;
		else if (x[i] > sx)
			pos[3]++;
	}
	
	px = sx;
	py = sy;
	c = distance(pos.begin(), max_element(pos.begin(), pos.end()));
	
	if (c == 0)			// Tent lies at the top side of school
		py = sy - 1;
	else if (c == 1)	// Tent lies at the bottom side of school
		py = sy + 1;
	else if (c == 2)	// Tent lies at the left side of school
		px = sx - 1;
	else				// Tent lies at the right side of school
		px = sx + 1;
	
	cout << pos[c] << endl;
	cout << px << " " << py;
}

int main() {
	int n, sx, sy;
	cin >> n >> sx >> sy;
	vector<int> x(n), y(n);
	for (int i = 0; i < n; i++)
		cin >> x[i] >> y[i];
	shawarma_tent(n, sx, sy, x, y);
	return 0;
}