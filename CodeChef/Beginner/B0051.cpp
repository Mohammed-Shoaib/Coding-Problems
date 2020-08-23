// Problem Code: ICPC16A

#include <iostream>

using namespace std;

string giveDirection(int x1, int y1, int x2, int y2) {
	int x = x2 - x1;
	int y = y2 - y1;
	if(x && y)
		return "sad";
	else if(x)
		return (x > 0) ? "right" : "left";
	else
		return (y > 0) ? "up" : "down";
}

int main() {
	int T, x1, y1, x2, y2;
	cin >> T;
	while(T--) {
		cin >> x1 >> y1 >> x2 >> y2;
		cout << giveDirection(x1, y1, x2, y2) << endl;
	}
	return 0;
}