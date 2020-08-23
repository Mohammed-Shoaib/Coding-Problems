// Problem Code: GRID

#include <iostream>
#include <vector>

using namespace std;

int sherlockAndGrid(int N, vector< vector<char> > grid) {
	int count = 0;
	vector< vector<bool> > rayX(N, vector<bool> (N)), rayY(N, vector<bool>(N));
	
	// Base Cases
	for (int i=0 ; i < N ; i++) {
		rayX[i][N - 1] = (grid[i][N - 1] == '.') ? true : false;
		rayY[N - 1][i] = (grid[N - 1][i] == '.') ? true : false;
	}

	// Edge Cases
	for (int i = N - 2 ; i >= 0 ; i--) {
		rayX[N - 1][i] = (grid[N - 1][i] == '.') ? rayX[N - 1][i + 1] : false;
		rayY[i][N - 1] = (grid[i][N - 1] == '.') ? rayY[i + 1][N - 1] : false;
	}

	// Using DP
	for (int i = N - 2 ; i >= 0 ; i--)
		for (int j = N - 2 ; j >= 0 ; j--) {
			rayX[i][j] = (grid[i][j] == '.') ? rayX[i][j + 1] : false;
			rayY[j][i] = (grid[j][i] == '.') ? rayY[j + 1][i] : false;
		}

	// Counting the valid points
	for (int i=0 ; i < N ; i++)
		for (int j=0 ; j < N ; j++)
			if (rayX[i][j] && rayY[i][j])
				count++;
	
	return count;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		vector< vector<char> > grid(N, vector<char>(N));
		for (int i=0 ; i < N ; i++)
			for (int j=0 ; j < N ; j++)
				cin >> grid[i][j];
		cout << sherlockAndGrid(N, grid) << endl;
	}
	return 0;
}