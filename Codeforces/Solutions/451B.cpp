// Problem Code: 451B
 
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void sort_the_array(int n, vector<int>& a) {
	int beg, end;
	beg = end = 0;
	
	while (end + 1 < n && a[end] < a[end + 1])
		end++;
	beg = end;
	
	while (end + 1 < n && a[end] > a[end + 1])
		end++;
	
	reverse(a.begin() + beg, a.begin() + end + 1);
	
	if (is_sorted(a.begin(), a.end())) {
		cout << "yes" << endl;
		cout << beg + 1 << " " << end + 1 << endl;
	}
	else
		cout << "no" << endl;
}

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int& x: a)
		cin >> x;
	sort_the_array(n, a);
	return 0;
}
