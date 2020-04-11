#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int allocation(int N, int B, vector<int>& A) {
	int h;
	sort(A.begin(), A.end());
	for(h = 0; h < N && A[h] <= B; h++)
		B -= A[h];
	return h;
}

int main() {
	int T;
	cin >> T;
	for (int x = 1; x <= T; x++) {
		int N, B;
		cin >> N >> B;
		vector<int> A(N);
		for (int i = 0; i < N; i++)
			cin >> A[i];
		cout << "Case #" << x << ": " << allocation(N, B, A) << endl;
	}
	return 0;
}