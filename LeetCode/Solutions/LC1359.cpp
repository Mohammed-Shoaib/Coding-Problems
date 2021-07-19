/*
Problem Statement: https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/
*/

class Solution {
public:
	int countOrders(int n) {
		int mod = 1e9 + 7;
		long long cnt = 1;
		for (int i = 1; i <= n; i++)
			cnt = (cnt * i * (i * 2 - 1)) % mod;
		return cnt;
	}
};