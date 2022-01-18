// Problem Code: 200B
 
#include <iostream>
#include <iomanip>
#include <vector>
#include <numeric>

using namespace std;

double drinks(int n, vector<int>& p) {
	return accumulate(p.begin(), p.end(), 0.0) / n;
}

int main() {
	cout << fixed << setprecision(5);
	
	int n;
	cin >> n;
	vector<int> p(n);
	
	for (int i = 0; i < n; i++)
		cin >> p[i];
	
	cout << drinks(n, p);
	
	return 0;
}