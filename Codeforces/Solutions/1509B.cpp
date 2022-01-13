/*
Problem Code: 1509B
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string tmt_document(int n, string& s) {
	int m_cnt, bal;
	m_cnt = bal = 0;
	
	for (int i = 0; i < n; i++) {
		if (s[i] == 'M')
			m_cnt++, bal--;
		else
			bal++;
		if (bal < 0)
			return "NO";
	}
	
	bal = 0;
	for (int i = n - 1; i >= 0; i--) {
		bal += 2 * (s[i] == 'T') - 1;
		if (bal < 0)
			return "NO";
	}
	
	return (m_cnt == bal) ? "YES" : "NO";
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		string s;
		cin >> n >> s;
		cout << tmt_document(n, s) << endl;
	}
	return 0;
}