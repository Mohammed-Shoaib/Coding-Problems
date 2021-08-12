/*
Problem Statement: https://leetcode.com/problems/design-circular-queue/
Space: O(k)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib

|--------------------|------|-------|
| Operations         | Time | Space |
|--------------------|------|-------|
| MyCircularQueue(k) | O(k) | O(1)  |
| enQueue(value)     | O(1) | O(1)  |
| deQueue()          | O(1) | O(1)  |
| Front()            | O(1) | O(1)  |
| Rear()             | O(1) | O(1)  |
| isEmpty()          | O(1) | O(1)  |
| isFull()           | O(1) | O(1)  |
|--------------------|------|-------|
*/

class MyCircularQueue {
private:
	int beg, size;
	vector<int> queue;
public:
	MyCircularQueue(int k): beg(0), size(0), queue(k) {}
	
	bool enQueue(int value) {
		if (isFull())
			return false;
		size++;
		queue[end()] = value;
		return true;
	}
	
	bool deQueue() {
		if (isEmpty())
			return false;
		size--;
		beg = (beg + 1) % queue.size();
		return true;
	}
	
	int end() {
		return (beg + size - 1) % queue.size();
	}
	
	int Front() {
		if (isEmpty())
			return -1;
		else
			return queue[beg];
	}
	
	int Rear() {
		if (isEmpty())
			return -1;
		else
			return queue[end()];
	}
	
	bool isEmpty() {
		return size == 0;
	}
	
	bool isFull() {
		return size == queue.size();
	}
};