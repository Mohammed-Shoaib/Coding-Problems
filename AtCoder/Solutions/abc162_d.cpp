// Problem Code: abc162_d

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

long long triplets(int N, string& S) {
	unordered_map<char, int> freq;

	for (char& c: S)
		freq[c]++;
	long long cnt *= 1LL * freq['R'] * freq['G'] * freq['B'];
	
	for (int i = 0; i < N; i++)
		for (int j = i + 1; j < N; j++) {
			// remove triplets where j - i == k - j
			int k = 2 * j - i;
			if (k < N && S[i] != S[j] && S[j] != S[k] && S[k] != S[i])
				cnt--;
		}
	
	return cnt;
}

int main() {
	int N;
	string S;
	cin >> N >> S;
	cout << triplets(N, S);
	return 0;
}