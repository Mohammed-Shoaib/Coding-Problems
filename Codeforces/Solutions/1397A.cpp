// Problem Code: 1397A

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string juggling_letters(int n, vector<string>& s) {
	vector<int> freq(26);
	
	for (int i = 0; i < n; i++)
		for (char& c: s[i])
			freq[c - 'a']++;
	
	for (int& x: freq)
		if (x % n != 0)
			return "NO";
	
	return "YES";
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<string> s(n);
		for (int i = 0; i < n; i++)
			cin >> s[i];
		cout << juggling_letters(n, s) << endl;
	}
	return 0;
}