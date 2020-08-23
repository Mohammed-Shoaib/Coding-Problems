#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <limits>

using namespace std;

const long long INF = numeric_limits<long long>::max();

bool is_possible(long long x, long long y) {
	return (x != INF && y != INF);
}

void compute(int i, int j, vector< vector<long long> > &p) {
	if (is_possible(p[i][j], p[i][j + 1]))
		p[i - 1][j] = p[i][j] + p[i][j + 1];
	else if (is_possible(p[i - 1][j], p[i][j + 1]))
		p[i][j] = p[i - 1][j] - p[i][j + 1];
	else if (is_possible(p[i - 1][j], p[i][j]))
		p[i][j + 1] = p[i - 1][j] - p[i][j];
}

string pyramid(int d, vector< vector<long long> > &p) {
	for (int k = 1; k <= d; k++)
		for (int i = d - 1; i > 0; i--)
			for (int j = 0; j < i; j++)
				compute(i, j, p);
	return (p[0][0] == INF) ? "Not solvable" : to_string(p[0][0]);
}

int main() {
	freopen("pyramid.in", "r", stdin);
	freopen("output.out", "w", stdout);
	
	int d, k = 1;
	while (cin >> d && d != -1) {
		string s;
		vector< vector<long long> > p(d);
		for (int i = 0; i < d; i++) {
			p[i] = vector<long long>(i + 1);
			for (int j = 0; j <= i; j++) {
				cin >> s;
				if (s == "-")
					p[i][j] = INF;
				else
					p[i][j] = stoll(s);
			}
		}
		cout << k << ": " << pyramid(d, p) << endl;
		k++;
	}
	
	return 0;
}