/*
Problem Statement: https://leetcode.com/problems/my-calendar-i/
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib

|------------------|--------------|-------|
| Operations       | Time         | Space |
|------------------|--------------|-------|
| MyCalendar()     | O(1)         | O(1)  |
| book(start, end) | O(n • log n) | O(1)  |
|------------------|--------------|-------|
*/

class MyCalendar {
private:
	map<int, int> slots;
public:
	MyCalendar() {}
	
	bool book(int start, int end) {
		auto it = slots.upper_bound(start);
		
		if (it != slots.end() && it->second < end)
			return false;
		slots.insert({end, start});
		
		return true;
	}
};