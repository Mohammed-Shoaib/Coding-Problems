/*
Problem Statement: https://leetcode.com/problems/design-underground-system/
*/

class UndergroundSystem {
private:
	unordered_map<int, pair<string, int>> cust;
	unordered_map<string, pair<double, int>> adj;
public:
	UndergroundSystem() {}
	
	void checkIn(int id, string stationName, int t) {
		cust[id] = {stationName, t};
	}
	
	void checkOut(int id, string s2, int t2) {
		string s = cust[id].first + " " + s2;
		adj[s].first += t2 - cust[id].second;
		adj[s].second++;
		cust.erase(id);
	}
	
	double getAverageTime(string startStation, string endStation) {
		string s = startStation + " " + endStation;
		return adj[s].first / adj[s].second;
	}
};