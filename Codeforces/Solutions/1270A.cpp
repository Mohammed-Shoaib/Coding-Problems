// Problem Code: 1270A

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string card_game(int n, vector<int>& a, vector<int>& b) {
	int max_card = *max_element(a.begin(), a.end());
	return (max_card == n) ? "YES" : "NO";
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, k1, k2;
		cin >> n >> k1 >> k2;
		vector<int> a(k1), b(k2);
		for (int i = 0; i < k1; i++)
			cin >> a[i];
		for (int i = 0; i < k2; i++)
			cin >> b[i];
		cout << card_game(n, a, b) << endl;
	}
	return 0;
}