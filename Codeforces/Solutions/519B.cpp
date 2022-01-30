// Problem Code: 519B
 
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int correction(vector<int>& a, vector<int>& b) {
	unordered_map<int, int> freq;
	
	for (int& x: a)
		freq[x]++;
	
	for (int& x: b)
		freq[x]--;
	
	for (auto& [k, v]: freq)
		if (v == 1)
			return k;
	
	return -1;
}

void compilation_errors(vector<int>& a, vector<int>& b, vector<int>& c) {
	cout << correction(a, b) << endl;
	cout << correction(b, c) << endl;
}

int main() {
	int n;
	cin >> n;
	vector<int> a(n), b(n - 1), c(n - 2);
	
	for (int& x: a)
		cin >> x;
	
	for (int& x: b)
		cin >> x;
	
	for (int& x: c)
		cin >> x;
	
	compilation_errors(a, b, c);
	
	return 0;
}
