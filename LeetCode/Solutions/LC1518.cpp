/*
Problem Statement: https://leetcode.com/problems/water-bottles/
Time: O(log n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int numWaterBottles(int numBottles, int numExchange) {
		int drink = numBottles;
		
		while (numBottles >= numExchange) {
			int newBottles = (numBottles / numExchange);
			drink += newBottles;
			numBottles = newBottles + (numBottles % numExchange);
		}
		
		return drink;
	}
};