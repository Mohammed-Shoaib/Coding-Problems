// Problem Code: 1333F

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void imperfection(int n) {
	vector<int> d(n + 1);
	
	// sieve of eratosthenes
	d[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (d[i])
			continue;
		for (int j = i; j <= n; j += i)
			if (!d[j])
				d[j] = j / i;
	}	
	
	sort(d.begin(), d.end());
	for (int i = 2; i <= n; i++)
		cout << d[i] << " ";
}

int main() {
	int n;
	cin >> n;
	imperfection(n);
	return 0;
}