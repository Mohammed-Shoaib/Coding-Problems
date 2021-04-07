#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void h_index(int N, vector<int>& A) {
	vector<int> H(N);
	priority_queue<int, vector<int>, greater<int>> pq;
	
	for (int i = 0; i < N; i++) {
		pq.push(A[i]);
		if (pq.size() > pq.top())
			pq.pop();
		H[i] = pq.size();
	}
	
	for (int i = 0; i < N; i++)
		cout << H[i] << " ";
	cout << endl;
}

int main() {
	int T;
	cin >> T;
	for (int x = 1; x <= T; x++) {
		int N;
		cin >> N;
		vector<int> A(N);
		for (int i = 0; i < N; i++)
			cin >> A[i];
		cout << "Case #" << x << ": ";
		h_index(N, A);
	}
	return 0;
}