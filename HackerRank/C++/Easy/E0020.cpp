/*
Problem Statement: https://www.hackerrank.com/challenges/cpp-maps/problem
*/

#include <iostream>
#include <map>

using namespace std;

void map_stl(int type, string X, int Y, map<string, int> &m) {
	if (type == 1)
		m[X] += Y;
	else if (type == 2)
		m.erase(X);
	else
		cout << m[X] << endl;
	return;
}

int main() {
	int Q;
	cin >> Q;
	map<string, int> m;
	while (Q--) {
		string X;
		int type, Y = 0;
		cin >> type >> X;
		if (type == 1)
			cin >> Y;
		map_stl(type, X, Y, m);
	}
	return 0;
}