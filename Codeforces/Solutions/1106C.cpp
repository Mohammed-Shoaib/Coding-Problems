// Problem Code: 1106C

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long numberDivision(int n, vector<int> S) {
	long long sum = 0;
	sort(S.begin(), S.end());
	for (int i = 0, j = n - 1; i < n / 2; i++, j--)
		sum += (long long) (S[i] + S[j]) * (S[i] + S[j]);
	return sum;
}

int main() {
	int n;
	cin >> n;
	vector<int> S(n);
	for (int i = 0; i < n; i++)
		cin >> S[i];
	cout << numberDivision(n, S);
	return 0;
}