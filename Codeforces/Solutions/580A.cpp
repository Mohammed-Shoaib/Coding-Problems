// Problem Code: 580A
 
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int kefa_and_first_steps(int n, vector<int>& a) {
	int max_len, len;
	max_len = len = 1;
	
	for (int i = 1; i < n; i++) {
		if (a[i] >= a[i - 1])
			len++;
		else
			len = 1;
		max_len = max(len, max_len);
	}
	
	return max_len;
}

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cout << kefa_and_first_steps(n, a);
	return 0;
}