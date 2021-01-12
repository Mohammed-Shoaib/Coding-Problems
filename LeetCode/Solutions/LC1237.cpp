/*
Problem Statement: https://leetcode.com/problems/find-positive-integer-solution-for-a-given-equation/
*/

class Solution {
public:
	vector< vector<int> > findSolution(CustomFunction& customfunction, int z) {
		int f, x, y;
		vector< vector<int> > res;
		x = 1;
		y = 1000;

		while (x <= 1000 && y >= 1) {
			f = customfunction.f(x, y);
			if (f == z)
				res.push_back({x++, y--});
			else if (f < z)
				x++;
			else
				y--;
		}
		
		return res;
	}
};