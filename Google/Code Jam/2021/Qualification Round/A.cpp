#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

int reversort(int N, vector<int>& L) {
	int cost = 0;
	
	for (int i = 0; i + 1 < N; i++) {
		int j = distance(L.begin(), min_element(L.begin() + i, L.end()));
		cost += j - i + 1;
		reverse(L.begin() + i, L.begin() + j + 1);
	}
	
	return cost;
}

int main() {
	int T;
	cin >> T;
	
	for (int x = 1; x <= T; x++) {
		int N;
		cin >> N;
		vector<int> L(N);
		for (int i = 0; i < N; i++)
			cin >> L[i];
		cout << "Case #" << x << ": " << reversort(N, L) << endl;
	}
	
	return 0;
}