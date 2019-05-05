/*
Problem Statement: https://www.hackerrank.com/challenges/organizing-containers-of-balls/problem
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string organizingContainers(int n, vector< vector<int> > &M) {
	vector<int> balls(n), containers(n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			balls[j] += M[i][j];
			containers[i] += M[i][j];
		}
	sort(balls.begin(), balls.end());
	sort(containers.begin(), containers.end());
	return (balls == containers) ? "Possible" : "Impossible";
}

int main() {
	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		vector< vector<int> > M(n, vector<int>(n));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> M[i][j];
		cout << organizingContainers(n, M) << endl;
	}
	return 0;
}