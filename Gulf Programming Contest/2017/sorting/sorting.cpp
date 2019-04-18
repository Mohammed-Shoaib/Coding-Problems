#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

void sorting(vector<int> &u, vector< vector<string> > &t) {
	if (u.size() == 0)
		return;
	sort(t.begin(), t.end(), [&](vector<string> l, vector<string> r) {
		int i = 0;
		string a, b;
		while (i < u.size() - 1 && l[ abs(u[i]) - 1] == r[ abs(u[i]) - 1])
			i++;
		a = l[ abs(u[i]) - 1];
		b = r[ abs(u[i]) - 1];
		return (u[i] < 0) ? a >= b : a <= b;
	});
}

int main() {
	freopen("sorting.in", "r", stdin);
	freopen("output.out", "w", stdout);

	int n;
	cin >> n;
	for (int z = 1; z <= n; z++) {
		int c, r, k, p;
		cin >> c >> r >> k;
		cout << "Table " << z << endl;
		vector< vector<string> > t(r, vector<string>(c));
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
				cin >> t[i][j];
		for (int zz = 1; zz <= k; zz++) {
			vector<int> u;
			while (cin >> p && p)
				u.push_back(p);
			vector< vector<string> > copy(t);
			cout << "Instruction " << zz << endl;
			sorting(u, copy);
			for (int j, i = 0; i < min(r, 5); i++) {
				for (j = 0; j < c; j++)
					cout << copy[i][j] << " ";
				cout << endl;
			}
		}
	}

	return 0;
}