// Problem Code: abc172_c

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int tsundoku(int N, int M, int K, vector<long long>& A, vector<long long>& B) {
	int read, sum_a, sum_b, j;
	sum_a = sum_b = j = 0;

	for (j = 0; j < M && sum_b + B[j] <= K; j++)
		sum_b += B[j];
	read = j;
	
	for (int i = 0; i < N; i++) {
		sum_a += A[i];
		if (sum_a > K)
			break;
		while (sum_a + sum_b > K)
			sum_b -= B[--j];
		read = max(i + 1 + j, read);
	}

	return read;
}

int main() {
	int N, M, K;
	cin >> N >> M >> K;
	vector<long long> A(N), B(M);
	for (int i = 0; i < N; i++)
		cin >> A[i];
	for (int i = 0; i < M; i++)
		cin >> B[i];
	cout << tsundoku(N, M, K, A, B);
	return 0;
}