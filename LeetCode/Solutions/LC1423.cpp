/*
Problem Statement: https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int maxScore(vector<int>& cardPoints, int k) {
		int max_score, score, n = cardPoints.size();
		max_score = score = accumulate(cardPoints.begin(), cardPoints.begin() + k, 0);
		
		for (int i = 0; i < k; i++) {
			score -= cardPoints[k - i - 1];
			score += cardPoints[n - i - 1];
			max_score = max(score, max_score);
		}
		
		return max_score;
	}
};