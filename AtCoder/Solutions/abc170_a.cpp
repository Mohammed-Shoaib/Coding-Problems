 // Problem Code: abc170_a

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int five_variables(vector<int>& x) {
	return 15 - accumulate(x.begin(), x.end(), 0);
}

int main() {
	vector<int> x(5);
	for (int i = 0; i < x.size(); i++)
		cin >> x[i];
	cout << five_variables(x);
	return 0;
}