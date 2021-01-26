/*
Problem Statement: https://leetcode.com/problems/find-winner-on-a-tic-tac-toe-game/
*/

class Solution {
public:
	string tictactoe(vector< vector<int> >& moves) {
		int r, c, p = 0;
		vector< vector<int> > score(2, vector<int>(8));
		
		for (int i = 0; i < moves.size(); i++, p ^= 1) {
			r = moves[i][0];
			c = moves[i][1];
			score[p][r]++;
			score[p][c + 3]++;
			if (r == c)
				score[p][6]++;
			if (r + c == 2)
				score[p][7]++;
		}
		
		for (int i = 0; i < score.size(); i++)
			for (int j = 0; j < score[i].size(); j++)
				if (score[i][j] == 3)
					return (i == 0) ? "A" : "B";
		
		return (moves.size() == 9) ? "Draw" : "Pending";
	}
};