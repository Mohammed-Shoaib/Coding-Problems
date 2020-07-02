/*
Problem Statement: https://leetcode.com/problems/word-search/
Time: O(n • m • (3 ^ len))
Space: O(len)
*/

class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) {
		int m, n;
		m = board.size();
		n = board[0].size();
		unordered_map<char, int> freq;
		vector<int> xdir = {-1, 0, 1, 0}, ydir = {0, -1, 0, 1};

		// helper function
		function<bool(int, int, int)> search = [&](int pos, int i, int j) -> bool {
			// base cases
			if (pos == word.length())
				return true;
			else if (i < 0 || i == m || j < 0 || j == n || word[pos] != board[i][j])
				return false;
			
			// recurse
			board[i][j] = '*';
			bool found = false;
			for (int k = 0; k < xdir.size() && !found; k++)
				found |= search(pos + 1, i + xdir[k], j + ydir[k]);
			board[i][j] = word[pos];
			
			return found;
		};

		// check if we have enough letters
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				freq[board[i][j]]++;
		for (char& c: word)
			if (--freq[c] < 0)
				return false;
		
		// search for word at each position
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				if (word[0] == board[i][j] && search(0, i, j))
					return true;
		
		return false;
	}
};