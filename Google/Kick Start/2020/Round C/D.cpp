#include <iostream>
#include <vector>
#include <functional>

using namespace std;

class FenwickTree {
private:
	vector<long long> ft;
public:
	FenwickTree(int n) : ft(n + 1) {}

	int LSB(int x) {
		return x & -x;
	}

	void update(int i, int val) {
		add(i, val - rsq(i, i));
	}

	void add(int i, int val) {
		while (i < ft.size()) {
			ft[i] += val;
			i += LSB(i);
		}
	}

	long long rsq(int i) {
		long long sum = 0;
		while (i > 0) {
			sum += ft[i];
			i -= LSB(i);
		}
		return sum;
	}

	long long rsq(int l, int r) {
		return rsq(r) - rsq(l - 1);
	}
};

int sign(int i) {
	return (i & 1) ? 1 : -1;
}

long long candies(int N, int Q, vector<int>& A) {
	long long sum = 0;
	vector<FenwickTree> ft(2, FenwickTree(N));
	
	// helper function to update element at position i to val
	auto update = [&](int i, int val) {
		ft[0].update(i, sign(i) * val);
		ft[1].update(i, sign(i) * i * val);
	};

	// helper function to query sum of range [l, r]
	auto query = [&](int l, int r) {
		long long s, ms;
		s  = ft[0].rsq(l, r);
		ms = ft[1].rsq(l, r);
		return sign(l) * (ms - (l - 1) * s);
	};

	// initialize fenwick trees
	for (int i = 1; i <= N; i++)
		update(i, A[i - 1]);
	
	// process queries
	while (Q--) {
		char c;
		int x, y;
		cin >> c >> x >> y;
		if (c == 'U')
			update(x, y);
		else
			sum += query(x, y);
	}

	return sum;
}

int main() {
	int T;
	cin >> T;
	for (int x = 1; x <= T; x++) {
		int N, Q;
		cin >> N >> Q;
		vector<int> A(N);
		for (int i = 0; i < N; i++)
			cin >> A[i];
		cout << "Case #" << x << ": " << candies(N, Q, A) << endl;
	}
	return 0;
}