// Problem Code: 1278D
 
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <set>
#include <algorithm>
 
using namespace std;
 
void DFS(int s, vector<bool>& visited, vector< vector<int> >& adj) {
	visited[s] = true;
	for (int v: adj[s])
		if (!visited[v])
			DFS(v, visited, adj);
}
 
string segment_tree(int n, vector< pair<int, int> >& seg) {
	int r, edges = 0;
	vector<bool> visited(n);
	set< pair<int, int> > sweep;
	vector< vector<int> > adj(n);
	sort(seg.begin(), seg.end());
	
	// Sweep line algorithm
	for (int j, i = 0; i < n && edges < n; i++) {
		for (auto it = sweep.begin(); it != sweep.end() && edges < n; ) {
			r = (*it).first;
			j = (*it).second;
 
			if (r < seg[i].first) {
				it = sweep.erase(it);
				continue;
			}
			else if (r > seg[i].second)
				break;
			
			adj[i].push_back(j);
			adj[j].push_back(i);
			edges++;
			it++;
		}
		sweep.insert({seg[i].second, i});
	}
 
	// Tree has exactly n - 1 edges
	if (edges != n - 1)
		return "NO";
 
	// Check if tree is connected
	DFS(0, visited, adj);
	
	return (count(visited.begin(), visited.end(), true) == n) ? "YES" : "NO";
}
 
int main() {
	int n;
	cin >> n;
	vector< pair<int, int> > seg(n);
	for (int i = 0; i < n; i++)
		cin >> seg[i].first >> seg[i].second;
	cout << segment_tree(n, seg);
	return 0;
}