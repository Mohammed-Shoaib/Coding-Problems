/*
Problem Statement: https://leetcode.com/problems/min-stack/
*/

class MinStack {
private:
	stack<int> st, min;
public:
	void push(int x) {
		if (min.empty() || x <= min.top())
			min.push(x);
		st.push(x);
	}
	
	void pop() {
		if (st.top() == min.top())
			min.pop();
		st.pop();
	}
	
	int top() {
		return st.top();
	}
	
	int getMin() {
		return min.top();
	}
};