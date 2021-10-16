// Problem Code: 1080C

#include <iostream>
#include <utility>
#include <vector>

using namespace std;

long long R(int x1, int y1, int x2, int y2) {
	return (long long) (x2 - x1 + 1) * (y2 - y1 + 1);
}

long long B(int x1, int y1, int x2, int y2) {
	bool isBlack = false;
	long long cells = R(x1, y1, x2, y2);
	if((x1 ^ y1) & 1)
		isBlack = true;
	return (isBlack) ? (cells + 1)/2 : cells/2;
}

long long W(int x1, int y1, int x2, int y2) {
	bool isWhite = true;
	long long cells = R(x1, y1, x2, y2);
	if ((x1 ^ y1) & 1)
		isWhite = false;
	return (isWhite) ? (cells + 1)/2 : cells/2;
}

pair<long long, long long> marshaAndTwoFriends(int n, int m, vector<pair<int, int>> points) {
	int x1, x2, x3, x4, x5, x6;
	int y1, y2, y3, y4, y5, y6;
	long long prod, white, black, cells;

	x1 = points[0].first;
	x2 = points[1].first;
	x3 = points[2].first;
	x4 = points[3].first;

	y1 = points[0].second;
	y2 = points[1].second;
	y3 = points[2].second;
	y4 = points[3].second;

	prod = (long long) n * m;
	black = prod/2;
	white = (prod + 1)/2;

	// Case white paint
	cells = B(x1, y1, x2, y2);
	black -= cells;
	white += cells;

	// Case black paint
	cells = W(x3, y3, x4, y4);
	white -= cells;
	black += cells;

	// Case intersect
	x5 = max(x1, x3);
	x6 = min(x2, x4);
	y5 = max(y1, y3);
	y6 = min(y2, y4);
	if (x5 <= x6 && y5 <= y6) {
		cells = B(x5, y5, x6, y6);
		black += cells;
		white -= cells;
	}

	return make_pair(white, black);
}

int main() {
	int t, n, m, x, y;
	vector<pair<int, int>> points(4);
	pair<long long, long long> results;
	
	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 0 ; i < points.size() ; i++) {
			cin >> x >> y;
			points[i] = make_pair(x, y);
		}
		results = marshaAndTwoFriends(n, m, points);
		cout << results.first << " " << results.second << endl;
	}
	return 0;
}