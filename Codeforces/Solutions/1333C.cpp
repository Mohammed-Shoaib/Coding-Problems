// Problem Code: 1333C

#include <iostream>
#include <vector>
#include <set>

using namespace std;

long long good(int n, vector<int>& a) {
	long long cnt = 0;
	set<long long> seen = {0};
	vector<long long> prefix(n + 1);

	for (int i = 0; i < n; i++)
		prefix[i + 1] = a[i] + prefix[i];
	
	for (int i = 0, j = 0; i < n; i++) {
		while (j < n && !seen.count(prefix[j + 1]))
			seen.insert(prefix[++j]);
		cnt += j - i;
		seen.erase(prefix[i]);
	}

	return cnt;
}

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cout << good(n, a);
	return 0;
}