/*
Problem Statement: https://leetcode.com/problems/minimum-number-of-flips-to-convert-binary-matrix-to-zero-matrix/
*/

class Solution {
private:
	int inf = numeric_limits<int>::max();
public:
	int minFlips(vector< vector<int> >& mat) {
		int length, states = 1 << (mat.size() * mat[0].size());
		vector<int> memo(states, inf);
		vector<bool> visited(states);

		// Initialize for zero and calculate length
		memo[0] = 0;
		visited[0] = true;
		length = backtrack(memo, visited, mat);
		
		return (length == inf) ? -1 : length;
	}

	int backtrack(vector<int>& memo, vector<bool>& visited, vector< vector<int> > mat) {
		int length, bits = get_binary(mat);
		
		// If state visited, return the calculated length
		if (visited[bits])
			return memo[bits];
		
		length = inf;
		visited[bits] = true;
		
		// Calculate length for state by getting the shortest length
		for (int i = 0; i < mat.size(); i++)
			for (int j = 0; j < mat[i].size(); j++) {
				flip(i, j, mat);
				length = min(backtrack(memo, visited, mat), length);
				flip(i, j, mat);
			}
		
		// To avoid integer overflow
		memo[bits] = (length == inf) ? inf : length + 1;
		return memo[bits];
	}

	int get_binary(vector< vector<int> >& mat) {
		int bits = 0;
		for (int i = 0; i < mat.size(); i++)
			for (int j = 0; j < mat[i].size(); j++) {
				bits <<= 1;
				bits |= mat[i][j];
			}
		return bits;
	}

	void flip(int i, int j, vector< vector<int> >& mat) {
		// Flip position and all its neighbours
		mat[i][j] ^= 1;
		if (i > 0)
			mat[i - 1][j] ^= 1;
		if (i < mat.size() - 1)
			mat[i + 1][j] ^= 1;
		if (j > 0)
			mat[i][j - 1] ^= 1;
		if (j < mat[0].size() - 1)
			mat[i][j + 1] ^= 1;
	}
};