#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string parenting_partnering_returns(int N, vector<int>& S, vector<int>& E) {
	string s(N, '?');
	vector<int> p(2);
	vector<vector<int>> a(N);
	vector<char> c = {'C', 'J'};
	
	for (int i = 0; i < N; i++)
		a[i] = {S[i], E[i], i};
	sort(a.begin(), a.end());

	for (vector<int>& act: a) {
		bool found = false;
		for (int i = 0; i < p.size() && !found; i++)
			if (p[i] <= act[0]) {
				s[act[2]] = c[i];
				p[i] = act[1];
				found = true;
			}
		if (!found)
			return "IMPOSSIBLE";
	}

	return s;
}

int main() {
	int T;
	cin >> T;
	for (int x = 1; x <= T; x++) {
		int N;
		cin >> N;
		vector<int> S(N), E(N);
		for (int i = 0; i < N; i++)
			cin >> S[i] >> E[i];
		cout << "Case #" << x << ": " << parenting_partnering_returns(N, S, E) << endl;
	}
	return 0;
}