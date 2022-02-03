// Problem Code: 141A
 
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string amusing_joke(string& s1, string& s2, string& s3) {
	vector<int> cnt(26);
	
	for (char& c: s1)
		cnt[c - 'A']++;
	
	for (char& c: s2)
		cnt[c - 'A']++;
	
	for (char& c: s3)
		cnt[c - 'A']--;
	
	return all_of(cnt.begin(), cnt.end(), [](int x) {
		return x == 0;
	}) ? "YES" : "NO";
}

int main() {
	string s1, s2, s3;
	cin >> s1 >> s2 >> s3;
	cout << amusing_joke(s1, s2, s3);
	return 0;
}