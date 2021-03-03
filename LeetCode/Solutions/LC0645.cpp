/*
Problem Statement: https://leetcode.com/problems/set-mismatch/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	vector<int> findErrorNums(vector<int>& nums) {
		/*
			x -> duplicate, y -> erased
			x - y = sum(nums) - sum(1...n)   ...(1)
			x² - y² = (x + y)(x - y) = sum(nums²) - sum(1²...n²)   ...(2)
			x + y = (2) / (1)   ...(3)
		*/
		int64_t a, b, n = nums.size();
		
		a = accumulate(nums.begin(), nums.end(), 0LL) - n * (n + 1) / 2;
		
		b = accumulate(nums.begin(), nums.end(), 0LL, [](int64_t sum, int64_t num) {
			return sum + num * num;
		}) - n * (n + 1) * ((n << 1) + 1) / 6;
		b /= a;
		
		return { static_cast<int>((a + b) / 2), static_cast<int>((b - a) / 2) };
	}
};