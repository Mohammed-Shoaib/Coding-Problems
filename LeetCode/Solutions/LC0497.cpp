/*
Problem Statement: https://leetcode.com/problems/random-point-in-non-overlapping-rectangles/
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib

|-----------------|----------|-------|
| Operations      | Time     | Space |
|-----------------|----------|-------|
| Solution(rects) | O(n)     | O(1)  |
| pick()          | O(log n) | O(1)  |
|-----------------|----------|-------|
*/

class Solution {
private:
	int area;
	mt19937 gen;
	vector<double> weights;
	vector<vector<int>> rects;
public:
	Solution(vector<vector<int>>& rects) : area(0), gen(random_device{}()), rects(rects) {
		for (vector<int>& rect: rects) {
			weights.push_back(get_area(rect));
			area += weights.back();
		}
		double sum = 0;
		for (double& weight: weights) {
			sum += weight;
			weight = sum / area;
		}
	}
	
	int get_area(vector<int>& rect) {
		return (rect[2] - rect[0] + 1) * (rect[3] - rect[1] + 1);
	}
	
	int get_random(int mn, int mx) {
		return uniform_int_distribution<int>{mn, mx}(gen);
	}
	
	vector<int> pick() {
		int x, y, pos;
		double prob = uniform_real_distribution<double>{0, 1}(gen);
		pos = distance(weights.begin(), lower_bound(weights.begin(), weights.end(), prob));
		vector<int>& rect = rects[pos];
		x = get_random(rect[0], rect[2]);
		y = get_random(rect[1], rect[3]);
		return {x, y};
	}
};