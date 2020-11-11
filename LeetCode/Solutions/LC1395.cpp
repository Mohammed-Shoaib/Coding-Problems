/*
Problem Statement: https://leetcode.com/problems/count-number-of-teams/
*/

class Solution {
public:
	int numTeams(vector<int>& rating) {
		int teams, n;
		teams = 0;
		n = rating.size();
		
		for (int i = 1; i < n - 1; i++) {
			vector<int> s(2), g(2);		// left = 0, right = 1
			for (int j = 0; j < n; j++) {
				s[j < i] += (rating[j] < rating[i]);
				g[j < i] += (rating[j] > rating[i]);
			}
			// teams formed by i = small[left] * greater[right] + greater[left] * small[right]
			teams += s[0] * g[1] + g[0] * s[1];
		}

		return teams;
	}
};