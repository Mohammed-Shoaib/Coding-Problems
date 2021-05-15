/*
Problem Statement: https://leetcode.com/problems/course-schedule-iii/
Time: O(n • log n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int scheduleCourse(vector<vector<int>> courses) {
		int dur, deadline, sum = 0;
		priority_queue<int> pq;
		
		sort(courses.begin(), courses.end(), [](auto& l, auto& r) {
			return l[1] < r[1];
		});
		
		for (auto& course: courses) {
			tie(dur, deadline) = {course[0], course[1]};
			sum += dur;
			pq.push(dur);
			if (sum > deadline) {
				sum -= pq.top();
				pq.pop();
			}
		}
		
		return pq.size();
	}
};