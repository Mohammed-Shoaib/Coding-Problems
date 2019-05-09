/*
Problem Statement: https://www.hackerrank.com/challenges/cpp-sets/problem
*/

#include <iostream>
#include <set>

using namespace std;

void sets_stl(int y, int x, set<int> &s) {
	if (y == 1)
		s.insert(x);
	else if (y == 2)
		s.erase(x);
	else if (s.find(x) != s.end())
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	return;
}

int main() {
	int Q;
	cin >> Q;
	set<int> s;
	while (Q--) {
		int y, x;
		cin >> y >> x;
		sets_stl(y, x, s);
	}
	return 0;
}