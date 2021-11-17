// Problem Code: 1272C

#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long count_substrings(string& s, vector<bool>& key) {
	int len = 0;
	long long sum = 0;
	for (char c: s) {
		if (key[c - 'a']) {
			len++;
			sum += len;
		} 
		else
			len = 0;
	}
	return sum;
}

int main() {
	char c;
	int n, k;
	string s;
	vector<bool> key(26);

	cin >> n >> k >> s;
	for (int i = 0; i < k; i++) {
		cin >> c;
		key[c - 'a'] = true;
	}
	cout << count_substrings(s, key);
	
	return 0;
}