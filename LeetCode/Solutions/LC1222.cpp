/*
Problem Statement: https://leetcode.com/problems/queens-that-can-attack-the-king/
Time: O(n²)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
		int n, qx, qy, ox, oy, kx, ky;
		bool blocked, cond1, cond2;
		vector<vector<int>> coords;
		
		n = queens.size();
		kx = king[0];
		ky = king[1];
		
		for (int i = 0; i < n; i++) {
			blocked = false;
			qx = queens[i][0];
			qy = queens[i][1];
			
			// check if queen can attack
			if (qx != kx && qy != ky && abs(qx - kx) != abs(qy - ky))
				continue;
			
			// check if queen is being blocked
			for (int j = 0; j < n && !blocked; j++) {
				ox = queens[j][0];
				oy = queens[j][1];
				
				// check if points are collinear
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