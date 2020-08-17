// Problem Code: 1398C

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

long long good_subarrays(int n, string& a) {
	int sum = 0;
	long long good = 0;
	unordered_map<int, int> freq;
	freq[0]++;
	
	for (int i = 0; i < n; i++) {
		sum += a[i] - '0';
		good += freq[sum - (i + 1)]++;
	}
	
	return good;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		string a;
		cin >> n >> a;
		cout << good_subarrays(n, a) << endl;
	}
	return 0;
}