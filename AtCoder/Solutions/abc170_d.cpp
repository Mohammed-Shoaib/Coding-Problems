// Problem Code: abc170_d

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int not_divisible(int N, vector<int>& A) {
	int cnt = 0, limit = *max_element(A.begin(), A.end());
	vector<bool> mark(limit + 1);
	unordered_map<int, int> freq;

	for (int x: A)
		freq[x]++;
	sort(A.begin(), A.end());

	for (int i = 0; i < N; i++) {
		if (mark[A[i]])
			continue;
		cnt += freq[A[i]] == 1;
		for (int x = A[i]; x <= limit; x += A[i])
			mark[x] = true;
	}

	return cnt;
}

int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; i++)
		cin >> A[i];
	cout << not_divisible(N, A);
	return 0;
}