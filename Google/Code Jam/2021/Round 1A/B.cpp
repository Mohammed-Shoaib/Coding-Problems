#include <iostream>
#include <numeric>
#include <functional>

using namespace std;

int prime_time(int M, vector<int>& P, vector<int>& N) {
	int score = 0;
	vector<int> nums;
	
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N[i]; j++)
			nums.push_back(P[i]);
	
	int L = nums.size();
	for (int b = 0; b < (1 << L); b++) {
		vector<int> A, B;
		for (int i = 0; i < L; i++) {
			if ((b >> i) & 1)
				A.push_back(nums[i]);
			else
				B.push_back(nums[i]);
		}
		if (A.empty() || B.empty())
			continue;
		int sum = accumulate(A.begin(), A.end(), 0);
		int64_t prod = accumulate(B.begin(), B.end(), 1LL, multiplies<int64_t>());
		if (sum == prod)
			score = max(sum, score);
	}
	
	return score;
}

int main() {
	int T;
	cin >> T;
	for (int x = 1; x <= T; x++) {
		int M;
		cin >> M;
		vector<int> P(M), N(M);
		for (int i = 0; i < M; i++)
			cin >> P[i] >> N[i];
		cout << "Case #" << x << ": " << prime_time(M, P, N) << endl;
	}
	return 0;
}