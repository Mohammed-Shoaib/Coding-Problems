/*
Problem Statement: https://leetcode.com/problems/reconstruct-itinerary/
Time Complexity: O(E log E)
Space Complexity: O(E)
*/

class Solution {
public:
	vector<string> findItinerary(vector<vector<string>>& tickets) {
		vector<string> order;
		unordered_map<string, vector<string>> adj;

		// hierholzer's algorithm
		function<void(string)> dfs = [&](string s) {
			vector<string>& v = adj[s];
			while (!v.empty()) {
				string u = v.back();
				v.pop_back();
				dfs(u);
			}
			order.push_back(s);
		};

		// construct adjacency list
		for (auto& t: tickets)
			adj[t[0]].push_back(t[1]);
		for (auto& [k, v]: adj)
			sort(v.rbegin(), v.rend());
		
		// euler path finding
		dfs("JFK");
		reverse(order.begin(), order.end());

		return order;
	}
};