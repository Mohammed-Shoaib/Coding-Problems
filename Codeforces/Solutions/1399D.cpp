// Problem Code: 1399D

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> subsequences(int n, string& s) {
	vector<int> chain(n);
	vector<vector<int>> seq(2);
	
	for (int i = 0; i < n; i++) {
		int pos = (s[i] == '1');
		if (seq[pos ^ 1].empty())
			seq[pos].push_back(seq[pos].size() + 1);
		else {
			seq[pos].push_back(seq[pos ^ 1].back());
			seq[pos ^ 1].pop_back();
		}
		chain[i] = seq[pos].back();
	}
	
	return chain;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		string s;
		cin >> n >> s;
		vector<int> chain = subsequences(n, s);
		cout << *max_element(chain.begin(), chain.end()) << endl;
		for (int i = 0; i < n; i++)
			cout << chain[i] << " ";
		cout << endl;
	}
	return 0;
}