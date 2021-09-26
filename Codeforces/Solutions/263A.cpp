// Problem Code: 263A
 
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int beautiful_matrix(int n, vector<vector<int>>& matrix) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (matrix[i][j])
				return abs(n / 2 - i) + abs(n / 2 - j);
	return -1;
}

int main() {
	int n = 5;
	vector<vector<int>> matrix(n, vector<int>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> matrix[i][j];
	cout << beautiful_matrix(n, matrix);
	return 0;
}