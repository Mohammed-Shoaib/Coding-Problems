// Problem Code: abc174_d

#include <iostream>
#include <string>

using namespace std;

int alter_altar(int N, string& c) {
	int cnt, l, r;
	cnt = l = 0;
	r = c.length() - 1;

	while (l < r) {
		if (c[l] != 'W')
			l++;
		else if (c[r] != 'R')
			r--;
		else {
			cnt++;
			swap(c[l], c[r]);
		}
	}

	return cnt;
}

int main() {
	int N;
	string c;
	cin >> N >> c;
	cout << alter_altar(N, c);
	return 0;
}