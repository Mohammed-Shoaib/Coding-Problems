// Problem Code: POINTS

#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

double dist(pair<int, int> p1, pair<int, int> p2) {
	return sqrt(pow(p2.first - p1.first, 2) + pow(p2.second - p1.second, 2));
}

double distanceTravelled(vector< pair<int, int> > points) {
	double d = 0;
	sort(points.begin(), points.end(), [] (pair<int, int> p1, pair<int, int> p2) {
		if (p1.first == p2.first)
			return p1.second >= p2.second;
		else
			return p1.first < p2.first;
	});
	for (int i = 1 ; i < points.size() ; i++)
		d += dist(points[i - 1], points[i]);
	return d;
}

int main() {
	cout << fixed << setprecision(2);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector< pair<int, int> > points(n);
		for (int i = 0 ; i < n ; i++)
			cin >> points[i].first >> points[i].second;
		cout << distanceTravelled(points) << endl;
	}
	return 0;
}