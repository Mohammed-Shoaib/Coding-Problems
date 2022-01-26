// Problem Code: 514B

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int lazer_gun(int n, int x0, int y0, vector<int>& x, vector<int>& y) {
	bool cx = false;
	unordered_set<double> s;

	for (int i = 0; i < n; i++) {
		if (x[i] - x0 == 0)
			cx = true;
		else
			s.insert((double) (y[i] - y0) / (x[i] - x0));
	}
	return s.size() + cx;
}

int main() {
	int n, x0, y0;
	cin >> n >> x0 >> y0;
	vector<int> x(n), y(n);
	for (int i = 0; i < n; i++)
		cin >> x[i] >> y[i];
	cout << lazer_gun(n, x0, y0, x, y);
	return 0;
}