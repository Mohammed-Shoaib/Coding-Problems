/*
Problem Statement: https://leetcode.com/problems/design-underground-system/
Space: O(n² • len)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib

|------------------------------------------|--------|--------|
| Operations                               | Time   | Space  |
|------------------------------------------|--------|--------|
| UndergroundSystem()                      | O(1)   | O(1)   |
| checkIn(id, stationName, t)              | O(len) | O(len) |
| checkOut(id, stationName, t)             | O(len) | O(len) |
| getAverageTime(startStation, endStation) | O(len) | O(len) |
|------------------------------------------|--------|--------|
*/

class UndergroundSystem {
private:
	unordered_map<string, pair<int, int>> adj;
	unordered_map<int, pair<string, int>> cust;
	
	string convert(string& s1, string& s2) {
		return s1 + "|" + s2;
	}
	
public:
	UndergroundSystem() {}
	
	void checkIn(int id, string stationName, int t) {
		cust[id] = {stationName, t};
	}
	
	void checkOut(int id, string stationName, int t) {
		auto& [startStation, startTime] = cust[id];
		pair<int, int>& p = adj[convert(startStation, stationName)];
		p.first += t - startTime;
		p.second++;
	}
	
	double getAverageTime(string startStation, string endStation) {
		pair<int, int>& p = adj[convert(startStation, endStation)];
		return (double) p.first / p.second;
	}
};