// Problem Code: 148A
 
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int lcm_n(vector<int> v) {
	int l = v[0];
	for (int& x: v)
		l = lcm(x, l);
	return l;
}

int insomnia_cure(int k, int l, int m, int n, int d) {
	int n1, n2, n3, n4;
	n1 = d / k + d / l + d / m + d / n;
	n2 = d / lcm(k, l) + d / lcm(k, m) + d / lcm(k, n)
	+ d / lcm(l, m) + d / lcm(l, n) + d / lcm(m, n);
	n3 = d / lcm_n({k, l, m}) + d / lcm_n({k, l, n})
	+ d / lcm_n({k, m, n}) + d / lcm_n({l, m, n});
	n4 = d / lcm_n({k, l, m, n});
	return n1 - n2 + n3 - n4;
}

int main() {
	int k, l, m, n, d;
	cin >> k >> l >> m >> n >> d;
	cout << insomnia_cure(k, l, m, n, d);
	return 0;
}