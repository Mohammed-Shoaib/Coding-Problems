// Problem Code: 231A

#include <iostream>
#include <vector>

using namespace std;

int team(vector<vector<int>>& problems) {
	int cnt = 0;
	for (auto& p: problems)
		cnt += (p[0] + p[1] + p[2] > 1);
	return cnt;
}

int main() {
	int n;
	cin >> n;
	vector<vector<int>> problems(n, vector<int>(3));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 3; j++)
			cin >> problems[i][j];
	cout << team(problems);
	return 0;
}