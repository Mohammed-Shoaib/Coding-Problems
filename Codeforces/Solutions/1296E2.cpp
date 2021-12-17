// Problem Code: 1296E2
 
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;
 
void string_coloring(int n, string& s) {
	vector<int> col(n);
	vector<char> seq = {'a'};
	
	for (int j, i = 0; i < n; i++) {
		int pos = distance(seq.begin(), find_if(seq.begin(), seq.end(), [val = s[i]](char c) {
			return c <= val;
		}));
		col[i] = pos;
		if (pos == seq.size())
			seq.push_back(s[i]);
		else
			seq[pos] = s[i];
	}
 
	cout << seq.size() << endl;
	for (int i = 0; i < n; i++)
		cout << col[i] + 1 << " ";
	cout << endl;
}
 
int main() {
	int n;
	string s;
	cin >> n >> s;
	string_coloring(n, s);
	return 0;
}