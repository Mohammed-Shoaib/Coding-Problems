#include <iostream>
#include <cstdio>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

int fair(int n, vector<int> cake) {
	int pos, diff, n1, n2;
	diff = numeric_limits<int>::max();
	sort(cake.begin(), cake.end());
	for(int i = cake.size() / 2, j = 1; i > 0 && i < cake.size(); i += j, j *= -1, (j < 0) ? j-- : j++)
		if (cake[i] - cake[i - 1] < diff) {
			diff = cake[i] - cake[i - 1];
			pos = i - 1;
		}
	n1 = cake[pos];
	n2 = cake[pos + 1];
	cake.erase(cake.begin() + pos, cake.begin() + pos + 2);
	for (int i = 0; i < n - 1; i++) {
		n1 *= 10;
		n2 *= 10;
		n1 += cake[cake.size() - i - 1];
		n2 += cake[i];
	}
	return n2 - n1;
}

int main() {
	freopen("fair.in", "r", stdin);
	freopen("output.out", "w", stdout);
	
	int K, n;
	while (cin >> K && K) {
		cin >> n;
		vector<int> cake(K);
		for (int i = 0; i < K; i++)
			cin >> cake[i];
		cout << fair(n, cake) << endl;
	}

	return 0;
}