// Problem Code: ROWCOLOP

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N, Q, K, X, result;
	string S;
	cin >> N >> Q;
	vector<int> row(N), col(N);
	while (Q--) {
		cin >> S >> K >> X;
		if (S == "RowAdd")
			row[K - 1] += X;
		else
			col[K - 1] += X;
	}
	result = *max_element(row.begin(), row.end()) + *max_element(col.begin(), col.end());
	cout << result;
	return 0;
}