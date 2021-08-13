/*
Problem Statement: https://leetcode.com/problems/design-circular-deque/
Space: O(k)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib

|--------------------|------|-------|
| Operations         | Time | Space |
|--------------------|------|-------|
| MyCircularDeque(k) | O(k) | O(1)  |
| insertFront(value) | O(1) | O(1)  |
| insertLast(value)  | O(1) | O(1)  |
| deleteFront()      | O(1) | O(1)  |
| deleteLast()       | O(1) | O(1)  |
| getFront()         | O(1) | O(1)  |
| getRear()          | O(1) | O(1)  |
| isEmpty()          | O(1) | O(1)  |
| isFull()           | O(1) | O(1)  |
|--------------------|------|-------|
*/

class MyCircularDeque {
private:
	int beg, size;
	vector<int> deque;
public:
	MyCircularDeque(int k): beg(0), size(0), deque(k) {}
	
	bool insertFront(int value) {
		if (isFull())
			return false;
		size++;
		beg = (beg - !isEmpty() + deque.size()) % deque.size();
		deque[beg] = value;
		return true;
	}
	
	bool insertLast(int value) {
		if (isFull())
			return false;
		size++;
		deque[end()] = value;
		return true;
	}
	
	bool deleteFront() {
		if (isEmpty())
			return false;
		size--;
		beg = (beg + 1) % deque.size();
		return true;
	}
	
	bool deleteLast() {
		if (isEmpty())
			return false;
		else
			return size--;
	}
	
	int end() {
		return (beg + size - 1) % deque.size();
	}
	
	int getFront() {
		if (isEmpty())
			return -1;
		else
			return deque[beg];		
	}
	
	int getRear() {
		if (isEmpty())
			return -1;
		else
			return deque[end()];
	}
	
	bool isEmpty() {
		return size == 0;
	}
	
	bool isFull() {
		return size == deque.size();
	}
};