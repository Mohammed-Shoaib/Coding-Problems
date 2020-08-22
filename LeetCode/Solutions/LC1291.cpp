/*
Problem Statement: https://leetcode.com/problems/sequential-digits/
*/

class Solution {
public:
	vector<int> sequentialDigits(int low, int high) {
		int num = 0;
		vector<int> seq;
		
		for (int i = 1; i <= 9; num = 0, i++)
			for (int j = i; j <= 9; j++) {
				num = 10 * num + j;
				seq.push_back(num);
			}
		
		sort(seq.begin(), seq.end());
		auto it_low = lower_bound(seq.begin(), seq.end(), low);
		auto it_high = upper_bound(seq.begin(), seq.end(), high);
		
		return vector<int>(it_low, it_high);
	}
};