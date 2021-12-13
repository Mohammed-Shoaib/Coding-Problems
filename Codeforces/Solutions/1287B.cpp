// Problem Code: 1287B

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

string find_card(string& a, string& b) {
	string c;
	for (int i = 0; i < a.length(); i++) {
		if (a[i] == b[i])
			c += a[i];
		else
			c += a[i] ^ b[i] ^ 'S' ^ 'E' ^ 'T';
	}
	return c;
}

long long hyperset(int n, vector<string>& cards) {
	long long ways = 0;
	unordered_set<string> seen(cards.begin(), cards.end());

	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (seen.count(find_card(cards[i], cards[j])))
				ways++;
	
	return ways / 3;
}

int main() {
	int n, k;
	cin >> n >> k;
	vector<string> cards(n);
	for (int i = 0; i < n; i++)
		cin >> cards[i];
	cout << hyperset(n, cards);
	return 0;
}