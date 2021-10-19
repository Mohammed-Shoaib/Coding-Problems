// Problem Code: 1234D

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class FenwickTree {
private:
	vector<int> ft;
public:
	FenwickTree(int n) : ft(n + 1) {}

	int LSB(int x) {
		return x & (-x);
	}

	void update(int i, int val) {
		while (i < ft.size()) {
			ft[i] += val;
			i += LSB(i);
		}
	}

	int rsq(int i) {
		int sum = 0;
		while (i != 0) {
			sum += ft[i];
			i -= LSB(i);
		}
		return sum;
	}

	int rsq(int i, int j) {
		return rsq(j) - rsq(i - 1);
	}
};

int main() {
	int q;
	string s;
	cin >> s >> q;
	vector<FenwickTree> ft(26, FenwickTree(s.length()));
	
	for (int i = 0; i < s.length(); i++)
		ft[s[i] - 'a'].update(i + 1, 1);
	
	while (q--) {
		char c;
		int t, pos, l, r;
		cin >> t;
		if (t == 1) {
			cin >> pos >> c;
			ft[s[pos - 1] - 'a'].update(pos, -1);
			ft[c - 'a'].update(pos, 1);
			s[pos - 1] = c;
		} else {
			int cnt = 0;
			cin >> l >> r;
			for (int i = 0; i < ft.size(); i++)
				cnt += (ft[i].rsq(l, r) > 0);
			cout << cnt << endl;
		}
	}
	
	return 0;
}