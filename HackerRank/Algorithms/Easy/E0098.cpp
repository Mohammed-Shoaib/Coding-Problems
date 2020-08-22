/*
Problem Statement: https://www.hackerrank.com/challenges/big-sorting/problem
*/

#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

vector<string> bigSorting(vector<string> &unsorted) {
	vector< pair<int, string> > nums(unsorted.size());
	for (int i = 0; i < nums.size(); i++)
		nums[i] = make_pair(unsorted[i].length(), unsorted[i]);
	sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size(); i++)
		unsorted[i] = nums[i].second;
	return unsorted;
}

int main() {
	int n;
	cin >> n;
	vector<string> sorted, unsorted(n);
	for (int i = 0; i < n; i++)
		cin >> unsorted[i];
	sorted = bigSorting(unsorted);
	for (int i = 0; i < n; i++)
		cout << sorted[i] << endl;
	return 0;
}