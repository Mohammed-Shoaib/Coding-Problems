// Problem Code: 1282C

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int petya_and_exam(int n, int T, int a, int b, vector<int>& d, vector<int>& t) {
	int points, easy, s, rem;
	vector< pair<int, int> > q(n);

	points = easy = s = 0;
	for (int i = 0; i < n; i++) {
		q[i] = {t[i], d[i]};
		easy += d[i] == 0;
	}
	q.push_back({T + 1, -1});
	sort(q.begin(), q.end());

	for (int i = 0; i <= n && s <= T; i++) {
		if (s < q[i].first) {
			rem = q[i].first - s - 1;
			points = max(i + min(rem / a, easy), points);
		}
		s += (q[i].second) ? b : a;
		easy -= q[i].second == 0;
	}

	return points;
}

int main() {
	int m;
	cin >> m;
	while (m--) {
		int n, T, a, b;
		cin >> n >> T >> a >> b;
		vector<int> d(n), t(n);
		for (int i = 0; i < n; i++)
			cin >> d[i];
		for (int i = 0; i < n; i++)
			cin >> t[i];
		cout << petya_and_exam(n, T, a, b, d, t) << endl;
	}
	return 0;
}