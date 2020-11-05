/*
Problem Statement: https://leetcode.com/problems/design-a-stack-with-increment-operation/
*/

class CustomStack {
private:
	int size;
	vector<int> st, lazy;
public:
	CustomStack(int maxSize) : size(0), st(maxSize), lazy(maxSize) {}
	
	void push(int x) {
		if (size < st.size())
			st[size++] = x;
	}
	
	int pop() {
		if (size == 0)
			return -1;
		if (--size)
			lazy[size - 1] += lazy[size];
		st[size] += exchange(lazy[size], 0);
		return st[size];
	}
	
	void increment(int k, int val) {
		if (size)
			lazy[min(k, size) - 1] += val;
	}
};