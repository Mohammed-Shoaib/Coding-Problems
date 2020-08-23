// Problem Code: COMMUTE

#include <iostream>
#include <vector>

using namespace std;

int theMorningCommute(int n, vector<int> &x, vector<int> &l, vector<int> &f) {
	int time = 0;
	for (int i = 0; i < n; i++) {
		if (time < x[i])
			time = x[i];
		else
			time += (f[i] - (time - x[i]) % f[i]) % f[i];
		time += l[i];
	}
	return time;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<int> x(n), l(n), f(n);
		for (int i = 0; i < n; i++)
			cin >> x[i] >> l[i] >> f[i];
		cout << theMorningCommute(n, x, l, f) << endl;
	}
	return 0;
}