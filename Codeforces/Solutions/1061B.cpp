// Problem Code: 1061B

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long viewsMatter(vector<int> a) {
	int prev, required;
	long long sum = 0;
	prev = 0;
	required = a.size();
	sort(a.begin(), a.end());
	for(int i=0 ; i<a.size() ; sum += a[i++])
		if(a[i] > prev)
			prev++;
	required += a[a.size()-1] - prev;
	return sum - required;
}

int main() {
	int n, m, num;
	vector<int> a;
	cin >> n >> m;
	for(int i=0 ; i<n ; i++) {
		cin >> num;
		a.push_back(num);
	}
	cout << viewsMatter(a);
	return 0;
}