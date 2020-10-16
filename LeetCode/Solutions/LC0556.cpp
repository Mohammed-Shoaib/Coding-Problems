/*
Problem Statement: https://leetcode.com/problems/next-greater-element-iii/
*/

class Solution {
public:
	int nextGreaterElement(int n) {
		int limit = numeric_limits<int>::max();
		string s = to_string(n);
		next_permutation(s.begin(), s.end());
		long long larger = stoll(s);
		return (larger > limit || larger <= n) ? -1 : larger;
	}
};