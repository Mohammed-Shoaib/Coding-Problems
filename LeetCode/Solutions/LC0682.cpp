/*
Problem Statement: https://leetcode.com/problems/baseball-game/
Time: O(n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int calPoints(vector<string>& ops) {
		vector<int> record;
		
		for (string& op: ops) {
			if (op[0] == 'C')
				record.pop_back();
			else if (op[0] == 'D')
				record.push_back(2 * record.back());
			else if (op[0] == '+') {
				int prev = record[record.size() - 2];
				record.push_back(prev + record.back());
			}
			else
				record.push_back(stoi(op));
		}
		
		return accumulate(record.begin(), record.end(), 0);
	}
};