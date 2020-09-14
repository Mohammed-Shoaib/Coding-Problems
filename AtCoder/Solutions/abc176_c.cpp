// Problem Code: abc176_c

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long step(int N, vector<int>& A) {
	int max_h = 0;
	long long cnt = 0;
	for (int& h: A) {
		max_h = max(h, max_h);
		cnt += max_h - h;
	}
	return cnt;
}

int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; i++)
		cin >> A[i];
	cout << step(N, A);
	return 0;
}