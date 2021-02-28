/*
Problem Statement: https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/
*/

class Solution {
public:
	vector<int> finalPrices(vector<int>& prices) {
		stack<int> st;
		
		// monotonic stack
		for (int i = 0; i < prices.size(); i++) {
			while (!st.empty() && prices[i] <= prices[st.top()]) {
				prices[st.top()] -= prices[i];
				st.pop();
			}
			st.push(i);
		}
		
		return prices;
	}
};