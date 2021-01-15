#include <iostream>
#include <vector>

using namespace std;

void high_buildings(int N, int A, int B, int C) {
	int sum = A + B - C;
	vector<int> heights;
	
	if (sum > N || N >= 2 && sum == 1) {
		cout << "IMPOSSIBLE" << endl;
		return;
	}
	
	heights.insert(heights.end(), A - C, N - 1);
	heights.insert(heights.end(), C, N);
	heights.insert(heights.end(), B - C, N - 1);
	heights.insert(heights.begin() + 1, N - sum, 1);
	
	for (int& height: heights)
		cout << height << " ";
	cout << endl;
}

int main() {
	int T;
	cin >> T;
	for (int x = 1; x <= T; x++) {
		int N, A, B, C;
		cin >> N >> A >> B >> C;
		cout << "Case #" << x << ": ";
		high_buildings(N, A, B, C);
	}
	return 0;
}