/*
Problem Statement: https://leetcode.com/problems/largest-number/
*/

class Solution {
public:
	string largestNumber(vector<int>& nums) {
		string s;
		sort(nums.rbegin(), nums.rend(), compare);
		if (nums.size() && nums[0] == 0)
			return "0";
		for (int num: nums)
			s += to_string(num);
		return s;
	}
	
	static bool compare(int l, int r) {
		if (l == 0 || r == 0)
			return l < r;
		
		int temp = r;
		long long ll = l, rr = r;
		
		while (temp) {
			ll *= 10;
			temp /= 10;
		}
		ll += r;
		
		temp = l;
		while (temp) {
			rr *= 10;
			temp /= 10;
		}
		rr += l;
		
		return ll < rr;
	}
};