/*
Problem Code: https://www.hackerrank.com/challenges/lilys-homework/problem
*/

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int minimumSwaps(int n, vector< pair<int, int> > &brr) {
	int swaps = 0;
	vector<bool> visited(n);

	for (int i = 0; i < n; i++) {
		if (visited[i] || brr[i].second == i) {
			continue;
		}
		int cycle_len, j;
		cycle_len = 0;
		j = i;
		while (!visited[j]) {
			visited[j] = true;
			j = brr[j].second;
			cycle_len++;
		}
		swaps += cycle_len - 1;
	}

	return swaps;
}

int lilysHomework(int n, vector<int> &arr) {
	int swaps = 0;
	vector< pair<int, int> > brr(n);
	
	for (int i = 0; i < n; i++)
		brr[i] = {arr[i], i};

	// Try Ascending
	sort(brr.begin(), brr.end());
	swaps = minimumSwaps(n, brr);

	// Try Descending
	sort(brr.rbegin(), brr.rend());
	swaps = min(minimumSwaps(n, brr), swaps);
	
	return swaps;
}

int main() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	cout << lilysHomework(n, arr);
	return 0;
}