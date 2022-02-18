// Problem Code: 344A
 
#include <iostream>
#include <vector>

using namespace std;

int magnets(int n, vector<string>& m) {
	int groups = 1;
	for (int i = 1; i < n; i++)
		groups += (m[i] != m[i - 1]);
	return groups;
}

int main() {
	int n;
	cin >> n;
	vector<string> m(n);
	for (int i = 0; i < n; i++)
		cin >> m[i];
	cout << magnets(n, m);
	return 0;
}