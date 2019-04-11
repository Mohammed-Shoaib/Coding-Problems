#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string palindrome(int n, int b) {
	vector<int> num, copy;
	while (n != 0) {
		num.push_back(n % b);
		n /= b;
	}
	copy = vector<int>(num);
	reverse(copy.begin(), copy.end());
	return (num == copy) ? "Yes" : "No";
}

int main() {
	freopen("palindrome.in", "r", stdin);
	freopen("output.out", "w", stdout);
	int n, b;
	while (cin >> n >> b && n && b)
		cout << palindrome(n, b) << endl;
	return 0;
}