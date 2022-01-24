// Problem Code: 489B
 
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int berSU_ball(int n, int m, vector<int>& a, vector<int>& b) {
	int pairs, i, j;
	pairs = i = j = 0;
	
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	
	while (i < n && j < m) {
		if (a[i] < b[j] - 1)
			i++;
		else if (a[i] - 1 > b[j])
			j++;
		else
			pairs++, i++, j++;
	}
	
	return pairs;
}

int main() {
	int n, m;
	cin >> n;
	vector<int> a(n);
	
	for (int& x: a)
		cin >> x;
	
	cin >> m;
	vector<int> b(m);
	
	for (int& x: b)
		cin >> x;
	
	cout << berSU_ball(n, m, a, b) << endl;
	
	return 0;
}
