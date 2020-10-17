/*
Problem Statement: https://leetcode.com/problems/daily-temperatures/
*/

class Solution {
public:
	vector<int> dailyTemperatures(vector<int>& T) {
		int n = T.size();
		stack<int> st;
		vector<int> wait(n);

		for (int j, i = 0; i < n; i++) {
			while (!st.empty() && T[st.top()] < T[i]) {
				int j = st.top();
				st.pop();
				wait[j] = i - j;
			}
			st.push(i);
		}

		return wait;
	}
};