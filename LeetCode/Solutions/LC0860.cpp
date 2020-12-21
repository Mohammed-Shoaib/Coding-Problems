/*
Problem Statement: https://leetcode.com/problems/lemonade-change/
*/

class Solution {
public:
	bool lemonadeChange(vector<int>& bills) {
		int cnt;
		vector<int> notes = {10, 5};
		unordered_map<int, int> change;

		for (auto& bill: bills) {
			change[bill]++;
			bill -= 5;
			for (int i = 0; i < notes.size(); i++){
				cnt = bill / notes[i];
				if (cnt > change[notes[i]])
					continue;
				change[notes[i]] -= cnt;
				bill -= notes[i] * cnt;
			}
			if (bill)
				return false;
		}
		
		return true;
	}
};