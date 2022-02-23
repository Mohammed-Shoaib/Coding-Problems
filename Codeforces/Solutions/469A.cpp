// Problem Code: 469A
 
#include <iostream>
#include <vector>
#include <set>

using namespace std;

string i_wanna_be_the_guy(int n, vector<int>& p, vector<int>& q) {
	set<int> seen(p.begin(), p.end());
	seen.insert(q.begin(), q.end());
	return n == seen.size() ? "I become the guy." : "Oh, my keyboard!";
}

int main() {
	int n, x;
	cin >> n >> x;
	vector<int> p(x);
	for (int i = 0; i < x; i++)
		cin >> p[i];
	cin >> x;
	vector<int> q(x);
	for (int i = 0; i < x; i++)
		cin >> q[i];
	cout << i_wanna_be_the_guy(n, p, q);
	return 0;
}