#include <iostream>
#include <vector>

using namespace std;

int bike_tour(int N, vector<int>& H) {
	int peaks = 0;
	for (int i = 1; i < N - 1; i++)
		if (H[i - 1] < H[i] && H[i] > H[i + 1])
			peaks++;
	return peaks;
}

int main() {
	int T;
	cin >> T;
	for (int x = 1; x <= T; x++) {
		int N;
		cin >> N;
		vector<int> H(N);
		for (int i = 0; i < N; i++)
			cin >> H[i];
		cout << "Case #" << x << ": " << bike_tour(N, H) << endl;
	}
	return 0;
}