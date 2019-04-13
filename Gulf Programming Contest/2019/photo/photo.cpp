#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

long long fact(int n) {
	long long prod = 1;
	for (int i = n; i > 1; i--)
		prod *= i;
	return prod;
}

long long photo(vector<int> num) {
	int count = 1;
	long long ways = 1;
	sort(num.begin(), num.end());
	for (int i = 1; i < num.size(); i++) {
		if (num[i - 1] == num[i])
			count++;
		else {
			ways *= fact(count);
			count = 1;
		}
	}
	ways *= fact(count);
	return ways;
}

int main() {
	freopen("photo.in", "r", stdin);
	freopen("output.out", "w", stdout);

	int n, k = 1;
	cin >> n;
	while (n--) {
		int m;
		cin >> m;
		vector<int> num(m);
		for (int i = 0; i < m; i++)
			cin >> num[i];
		cout << k << ". " << photo(num) << endl;
		k++;
	}

	return 0;
}