/*
Problem Statement: https://leetcode.com/problems/distribute-candies-to-people/
Time: O(n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	vector<int> distributeCandies(int candies, int n) {
		int full, turns, last;
		full = sqrt(2 * candies + 0.25) - 0.5;
		turns = full / n;
		last = full % n;
		vector<int> people(n);
		
		// distribute for full turns
		for (int i = 0; i < n; i++)
			people[i] = turns * (i + 1) + n * turns * (turns - 1) / 2;
		
		// distribute for leftover turns
		for (int i = 0; i < last; i++)
			people[i] += turns * n + (i + 1);
		
		// distribute remaining to the last person
		people[last] += candies - full * (full + 1) / 2;
		
		return people;
	}
};