// Problem Code: 1234B1
 
#include <iostream>
#include <vector>
#include <deque>
#include <set>
 
using namespace std;
 
void social_network(int n, int k, vector<int>& id) {
	deque<int> d;
	set<int> seen;
	for (int i = 0; i < n; i++) {
		if (seen.find(id[i]) != seen.end())
			continue;
		if (d.size() == k) {
			seen.erase(d.front());
			d.pop_front();
		}
		d.push_back(id[i]);
		seen.insert(id[i]);
	}
	cout << d.size() << endl;
	for (int i = d.size() - 1; i >= 0; i--)
		cout << d[i] << " ";
}
 
int main() {
	int n, k;
	cin >> n >> k;
	vector<int> m, id(n);
	for (int i = 0; i < n; i++)
		cin >> id[i];
	social_network(n, k, id);
	return 0;
}