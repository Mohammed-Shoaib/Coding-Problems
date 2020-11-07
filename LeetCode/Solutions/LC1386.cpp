/*
Problem Statement: https://leetcode.com/problems/cinema-seat-allocation/
*/

class Solution {
public:
	int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
		int cnt, left, mid, right;
		left = 0b0111100000;
		mid = 0b0001111000;
		right = 0b0000011110;
		unordered_map<int, int> m;

		for (int i = 0; i < reservedSeats.size(); i++)
			m[reservedSeats[i][0]] |= 1 << (reservedSeats[i][1] - 1);
		
		cnt = 2 * (n - m.size());
		for (auto it: m) {
			int bm = it.second;
			cnt += !((bm & left) && (bm & mid) && (bm & right));
			cnt += !(bm & (left | right));
		}

		return cnt;
	}
};