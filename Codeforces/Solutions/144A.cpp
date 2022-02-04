// Problem Code: 144A
 
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

int arrival_of_the_general(int n, vector<int>& a) {
	int mn_pos, mx_pos, moves = 0;
	auto [mn, mx] = minmax_element(a.begin(), a.end());
	mn_pos = distance(find(a.rbegin(), a.rend(), *mn), a.rend()) - 1;
	mx_pos = distance(a.begin(), find(a.begin(), a.end(), *mx));
	return mx_pos + n - mn_pos - 1 - (mn_pos < mx_pos);
}

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cout << arrival_of_the_general(n, a);
	return 0;
}