/*
Problem Statement: https://leetcode.com/problems/online-stock-span/
*/

class StockSpanner {
private:
	stack<pair<int, int>> st;
public:
	StockSpanner() {}
	
	int next(int price) {
		int pops = 1;
		while (!st.empty() && st.top().first <= price) {
			pops += st.top().second;
			st.pop();
		}
		st.push({price, pops});
		return pops;
	}
};