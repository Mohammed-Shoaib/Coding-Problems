/*
Problem Statement: https://leetcode.com/problems/prison-cells-after-n-days/
Time: O(n • 2ⁿ) -> O(1)
Space: O(2ⁿ) -> O(1)
*/

class Solution {
public:
	vector<int> prisonAfterNDays(vector<int>& cells, int N) {
		int b, n = cells.size();
		vector<int> states;
		
		while (N--) {
			vector<int> nxt(cells.size());
			for (int i = 1; i < n - 1; i++)
				nxt[i] = (cells[i - 1] == cells[i + 1]);
			
			cells = nxt;
			b = convert(cells);
			if (!states.empty() && states[0] == b) {
				b = states[N % states.size()];
				break;
			}
			states.push_back(b);
		}

		for (int i = 0; i < n; i++) {
			int mask = b >> (n - i - 1);
			cells[i] = mask & 1;
		}
		
		return cells;
	}

	int convert(vector<int>& cells) {
		int b = 0;
		for (int& cell: cells) {
			b <<= 1;
			b |= cell;
		}
		return b;
	}
};