// Problem Code: 1265D

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> sequence(vector<int>& a) {
	int x;
	vector<int> b, seq;

	for (int i = 0; i < a.size(); i++) {
		x = i;
		b = a;
		while (b[x] && x < 4) {
			b[x]--;
			seq.push_back(x);
			x += (x && b[x - 1]) ? -1 : 1;
		}
		if (*max_element(b.begin(), b.end()) == 0)
			break;
		seq.clear();
	}

	return seq;
}

int main() {
	vector<int> seq, a(4);
	for (int i = 0; i < a.size(); i++)
		cin >> a[i];
	seq = sequence(a);
	if (seq.size())
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	for (int i = 0; i < seq.size(); i++)
		cout << seq[i] << " ";
	return 0;
}