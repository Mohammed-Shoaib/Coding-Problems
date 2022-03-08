// Problem Code: 1538B
 
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int friends_and_candies(int n, vector<int>& a) {
	int cnt = 0, sum = accumulate(a.begin(), a.end(), 0);
	
	if (sum % n != 0)
		return -1;
	sum /= n;
	
	for (int& x: a)
		cnt += (x > sum);
	
	return cnt;
}

int main() {
	int t;
	cin >> t;
	
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		
		for (int& x: a)
			cin >> x;
		
		cout << friends_and_candies(n, a) << endl;
	}
	
	return 0;
}
