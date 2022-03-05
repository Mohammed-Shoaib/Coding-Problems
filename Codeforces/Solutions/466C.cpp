// Problem Code: 466C
 
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int64_t number_of_ways(int n, vector<int>& a) {
	int64_t ways = 0, total_sum = accumulate(a.begin(), a.end(), static_cast<int64_t>(0));
	
	if (total_sum % 3 != 0)
		return 0;
	total_sum /= 3;
	
	int64_t sum = 0;
	vector<int64_t> prefix(n + 1);
	
	for (int i = n - 1; i >= 0; i--) {
		sum += a[i];
		prefix[i] = (sum == total_sum);
		prefix[i] += prefix[i + 1];		
	}
	
	sum = 0;
	for (int i = 0; i + 1 < n; i++) {
		sum += a[i];
		if (sum == total_sum)
			ways += prefix[i + 2];
	}
	
	return ways;
}

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int& x: a)
		cin >> x;
	cout << number_of_ways(n, a);
	return 0;
}
