// Problem Code: 1108B

#include <iostream>
#include <vector>
#include <set>
#include <utility>
#include <algorithm>

using namespace std;

pair<int, int> divisorsOfTwoIntegers(int n, vector<int> A) {
	int x, y;
	set<int> B;
	sort(A.begin(), A.end());
	y = A[n - 1];
	for (int i = n - 1; i >= 0; i--)
		if (y % A[i] == 0 && B.find(A[i]) == B.end()) {
			A.erase(A.begin() + i);
			B.insert(A[i]);
			n--;
		}
	x = A[n - 1];
	return make_pair(x, y);
}

int main() {
	int n;
	cin >> n;
	vector<int> A(n);
	pair<int, int> ans;
	for (int i = 0; i < n; i++)
		cin >> A[i];
	ans = divisorsOfTwoIntegers(n, A);
	cout << ans.first << " " << ans.second;
	return 0;
}