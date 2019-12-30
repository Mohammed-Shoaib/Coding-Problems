/*
Problem Statement: https://www.hackerrank.com/challenges/30-queues-stacks/problem
*/

#include <iostream>
#include <stack>
#include <queue>

using namespace std;

class Solution {
private:
	stack<int> st;
	queue<int> q;
public:
	void pushCharacter(char ch) {
		st.push(ch);
	}

	void enqueueCharacter(char ch) {
		q.push(ch);
	}

	char popCharacter() {
		char ch = st.top();
		st.pop();
		return ch;
	}

	char dequeueCharacter() {
		char ch = q.front();
		q.pop();
		return ch;
	}
};