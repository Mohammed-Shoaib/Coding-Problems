/*
Problem Statement: https://leetcode.com/problems/next-greater-element-ii/
*/

class Solution {
public:
	vector<int> nextGreaterElements(vector<int>& nums) {
		int n = nums.size();
		stack<int> st;
		vector<int> larger(n, -1);

		// monotonic stack
		for (int i = 0; i < 2 * n; i++) {
			while (!st.empty() && nums[i % n] > nums[st.top()]) {
				larger[st.top()] = nums[i % n];
				st.pop();
			}
			st.push(i % n);
		}

		return larger;
	}
};