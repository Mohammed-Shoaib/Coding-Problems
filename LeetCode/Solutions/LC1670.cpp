/*
Problem Statement: https://leetcode.com/problems/design-circular-queue/
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib

|------------------------|------|-------|
| Operations             | Time | Space |
|------------------------|------|-------|
| FrontMiddleBackQueue() | O(1) | O(1)  |
| pushFront(val)         | O(1) | O(1)  |
| pushMiddle(val)        | O(1) | O(1)  |
| pushBack(val)          | O(1) | O(1)  |
| popFront()             | O(1) | O(1)  |
| popMiddle()            | O(1) | O(1)  |
| popBack()              | O(1) | O(1)  |
|------------------------|------|-------|
*/

class FrontMiddleBackQueue {
private:
	list<int> front_q, back_q;
	
	void rebalance() {
		if (front_q.size() > back_q.size()) {
			back_q.push_front(front_q.back());
			front_q.pop_back();
		} else if (back_q.size() > 1 + front_q.size()) {
			front_q.push_back(back_q.front());
			back_q.pop_front();
		}
	}
	
public:
	FrontMiddleBackQueue() {}
	
	void pushFront(int val) {
		front_q.push_front(val);
		rebalance();
	}
	
	void pushMiddle(int val) {
		back_q.push_front(val);
		rebalance();
	}
	
	void pushBack(int val) {
		back_q.push_back(val);
		rebalance();
	}
	
	int popFront() {
		int val = -1;
		if (back_q.empty())
			return val;
		
		list<int>& queue = front_q.empty() ? back_q : front_q;
		val = queue.front();
		queue.pop_front();
		rebalance();
		
		return val;
	}
	
	int popMiddle() {
		int val = -1;
		
		if (back_q.empty())
			return val;
		else if (front_q.size() == back_q.size()) {
			val = front_q.back();
			front_q.pop_back();
		} else {
			val = back_q.front();
			back_q.pop_front();
		}
		rebalance();
		
		return val;
	}
	
	int popBack() {
		int val = -1;
		if (back_q.empty())
			return val;
		
		val = back_q.back();
		back_q.pop_back();
		rebalance();
		
		return val;
	}
};