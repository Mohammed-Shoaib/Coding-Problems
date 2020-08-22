/*
Problem Code: https://www.hackerrank.com/challenges/crush/problem
*/

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

long long arrayManipulation(int n, vector< tuple<int, int, int> > &queries) {
	int a, b, k;
	vector<long long> arr(n);
	for (int i = 0; i < queries.size(); i++) {
		tie(a, b, k) = queries[i];
		arr[a - 1] += k;
		arr[b] 	-= k;
	}
	for (int i = 1; i < n; i++)
		arr[i] += arr[i - 1];
	return *max_element(arr.begin(), arr.end());
}

int main() {
	int n, m;
	cin >> n >> m;
	vector< tuple<int, int, int> > queries(m);
	for (int i = 0; i < m; i++) {
		int a, b, k;
		cin >> a >> b >> k;
		queries[i] = make_tuple(a, b, k);
	}
	cout << arrayManipulation(n, queries);
	return 0;
}