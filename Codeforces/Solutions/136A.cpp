// Problem Code: 136A
 
#include <iostream>
#include <vector>

using namespace std;

vector<int> presents(int n, vector<int>& p) {
	vector<int> q(n);
	for (int i = 0; i < n; i++)
		q[p[i] - 1] = i + 1;
	return q;
}

int main() {
	int n;
	cin >> n;
	vector<int> p(n);
	for (int i = 0; i < n; i++)
		cin >> p[i];
	p = presents(n, p);
	for (int i = 0; i < n; i++)
		cout << p[i] << " ";
	cout << endl;
	return 0;
}