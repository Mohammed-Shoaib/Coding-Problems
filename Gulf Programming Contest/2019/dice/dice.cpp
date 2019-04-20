#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

pair<int, int> dice(vector<int> att, vector<int> def) {
	int L, R, size;
	L = R = 0;
	size = min(att.size(), def.size());
	sort(att.rbegin(), att.rend());
	sort(def.rbegin(), def.rend());
	for (int i = 0; i < size; i++)
		(att[i] <= def[i]) ? L++ : R++;
	return {L, R};
}

int main() {
	freopen("dice.in", "r", stdin);
	freopen("output.out", "w", stdout);
	
	int T, k = 1;
	cin >> T;
	while (T--) {
		int A, D;
		pair<int, int> res;
		cin >> A >> D;
		vector<int> att(A), def(D);
		for (int i = 0; i < A; i++)
			cin >> att[i];
		for (int i = 0; i < D; i++)
			cin >> def[i];
		res = dice(att, def);
		cout << k << ". " << res.first << " " << res.second << endl;
		k++;
	}

	return 0;
}