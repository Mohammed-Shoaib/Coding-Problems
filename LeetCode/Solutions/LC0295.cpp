/*
Problem Statement: https://leetcode.com/problems/find-median-from-data-stream/
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib

|----------------|----------|-------|
| Operations     | Time     | Space |
|----------------|----------|-------|
| MedianFinder() | O(1)     | O(1)  |
| addNum(num)    | O(log n) | O(1)  |
| rebalance()    | O(log n) | O(1)  |
| findMedian()   | O(1)     | O(1)  |
|----------------|----------|-------|
*/

class MedianFinder {
private:
	priority_queue<int> max_heap;
	priority_queue<int, vector<int>, greater<int>> min_heap;
public:
	MedianFinder() {}
	
	void addNum(int num) {
		if (max_heap.empty() || num < max_heap.top())
			max_heap.push(num);
		else
			min_heap.push(num);
		rebalance();
	}
	
	void rebalance() {
		if (max_heap.size() - min_heap.size() == 2) {
			min_heap.push(max_heap.top());
			max_heap.pop();
		} else if (min_heap.size() - max_heap.size() == 2) {
			max_heap.push(min_heap.top());
			min_heap.pop();
		}
	}
	
	double findMedian() {
		if (max_heap.size() > min_heap.size())
			return max_heap.top();
		else if (min_heap.size() > max_heap.size())
			return min_heap.top();
		else
			return (max_heap.top() + min_heap.top()) / 2.0;
	}
};