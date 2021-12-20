// Problem Code: 1374E1

#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int reading_books(int n, int k, vector<int>& t, vector<int>& a, vector<int>& b) {
	int total = 0;
	priority_queue<int> max_pq;
	priority_queue<int, vector<int>, greater<int>> min_pq[3];
	
	for (int i = 0; i < n; i++) {
		if (a[i] && b[i])
			max_pq.push(t[i]);
		else if (a[i] || b[i])
			min_pq[2 * a[i] + b[i]].push(t[i]);
	}
	
	while (!min_pq[1].empty() && !min_pq[2].empty()) {
		max_pq.push(min_pq[1].top() + min_pq[2].top());
		min_pq[1].pop();
		min_pq[2].pop();
	}

	if (max_pq.size() < k)
		return -1;
	while (max_pq.size() > k)
		max_pq.pop();
	
	while (!max_pq.empty()) {
		total += max_pq.top();
		max_pq.pop();
	}
	
	return total;
}

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> t(n), a(n), b(n);
	for (int i = 0; i < n; i++)
		cin >> t[i] >> a[i] >> b[i];
	cout << reading_books(n, k, t, a, b);
	return 0;
}