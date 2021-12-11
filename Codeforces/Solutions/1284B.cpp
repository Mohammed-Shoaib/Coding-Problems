// Problem Code: 1284B

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool is_ascent(vector<int>& s) {
	for (int i = 1; i < s.size(); i++)
		if (s[i - 1] < s[i])
			return true;
	return false;
}

long long ascent_sequences(int n, vector< vector<int> >& s) {
	long long seq = (long long) n * n;
	vector<int> f, l; 
	for (int i = 0; i < n; i++) 
		if (!is_ascent(s[i])) {
			f.push_back(s[i].front());
			l.push_back(s[i].back());
		}
	sort(f.begin(), f.end());
	for (int last: l)
		seq -= distance(f.begin(), upper_bound(f.begin(), f.end(), last));
	return seq;
}

int main() {
	int n, l;
	cin >> n;
	vector< vector<int> > s(n);
	for (int i = 0; i < n; i++) {
		cin >> l;
		s[i] = vector<int>(l);
		for (int j = 0; j < l; j++)
			cin >> s[i][j];
	}
	cout << ascent_sequences(n, s);
	return 0;
}