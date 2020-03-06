/*
Problem Statement: https://leetcode.com/problems/queens-that-can-attack-the-king/
*/

class Solution {
public:
    vector< vector<int> > queensAttacktheKing(vector< vector<int> > &queens, vector<int> &king) {
		int qx, qy, ox, oy, kx, ky;
		bool blocked, cond1, cond2;
		vector< vector<int> > coords;
		
		kx = king[0];
		ky = king[1];
		
		for (int i = 0; i < queens.size(); i++) {
			blocked = false;
			qx = queens[i][0];
			qy = queens[i][1];

			// Check if queen can attack
			if (qx != kx && qy != ky && abs(qx - kx) != abs(qy - ky))
				continue;

			// Check if queen is being blocked
			for (int j = 0; j < queens.size() && !blocked; j++) {
				ox = queens[j][0];
				oy = queens[j][1];

				// Check if points are collinear
				if (j == i || (ky - oy) * (ox - qx) != (oy - qy) * (kx - ox))
					continue;
				else if ((min(qy, ky) < oy && oy < max(qy, ky)) || (min(qx, kx) < ox && ox < max(qx, kx)))
					blocked = true;
			}
			
			if (!blocked)
				coords.push_back(queens[i]);
		}

		return coords;
    }
};