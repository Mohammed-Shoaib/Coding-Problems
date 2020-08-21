/*
Problem Statement: https://leetcode.com/problems/range-sum-query-mutable/
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib

|----------------|----------|-------|
| Operations     | Time     | Space |
|----------------|----------|-------|
| update(i, val) | O(log n) | O(1)  |
| sumRange(i, j) | O(log n) | O(1)  |
|----------------|----------|-------|
*/

class FenwickTree {
private:
	vector<int> ft;
public:
	FenwickTree(vector<int>& nums) : ft(nums.size() + 1) {
		for (int i = 0; i < nums.size(); i++)
			update(i + 1, nums[i]);
	}
	
	int LSB(int x) {
		return x & (-x);
	}
	
	void update(int i, int val) {
		while (i < ft.size()) {
			ft[i] += val;
			i += LSB(i);
		}
	}
	
	int rsq(int i) {
		int sum = 0;
		while (i != 0) {
			sum += ft[i];
			i -= LSB(i);
		}
		return sum;
	}
	
	int rsq(int i, int j) {
		return rsq(j) - rsq(i - 1);
	}
};

class NumArray {
private:
	FenwickTree ft;
	vector<int> nums;
public:
	NumArray(vector<int>& nums) : ft(nums), nums(nums) {}
	
	void update(int i, int val) {
		ft.update(i + 1, val - nums[i]);
		nums[i] = val;
	}
	
	int sumRange(int i, int j) {
		return ft.rsq(i + 1, j + 1);
	}
};