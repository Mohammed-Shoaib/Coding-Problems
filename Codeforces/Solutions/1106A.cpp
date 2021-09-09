// Problem Code: 1106A

#include <iostream>
#include <vector>

using namespace std;

int crossCounting(int n, vector< vector<char> > M) {
	int count = 0;
	for (int i = 1; i < n - 1; i++)
		for (int j = 1; j < n - 1; j++)
			if (M[i - 1][j - 1] == M[i - 1][j + 1] &&
				M[i - 1][j + 1] == M[i + 1][j - 1] &&
				M[i + 1][j - 1] == M[i + 1][j + 1] &&
				M[i + 1][j + 1] == M[i][j] &&
				M[i][j] == 'X')
				count++;
	return count;
}

int main() {
	int n;
	cin >> n;
	vector< vector<char> > M(n, vector<char> (n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> M[i][j];
	cout << crossCounting(n, M);
	return 0;
}