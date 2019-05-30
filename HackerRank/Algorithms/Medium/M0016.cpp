/*
Problem Statement: https://www.hackerrank.com/challenges/magic-square-forming/problem
*/

#include <iostream>
#include <valarray>
#include <numeric>
#include <limits>
#include <algorithm>

using namespace std;

const valarray< valarray< valarray<int> > > squares = {
	{ {8, 1, 6}, {3, 5, 7}, {4, 9, 2} },
	{ {6, 1, 8}, {7, 5, 3}, {2, 9, 4} },
	{ {4, 9, 2}, {3, 5, 7}, {8, 1, 6} },
	{ {2, 9, 4}, {7, 5, 3}, {6, 1, 8} }, 
	{ {8, 3, 4}, {1, 5, 9}, {6, 7, 2} },
	{ {4, 3, 8}, {9, 5, 1}, {2, 7, 6} }, 
	{ {6, 7, 2}, {1, 5, 9}, {8, 3, 4} }, 
	{ {2, 7, 6}, {9, 5, 1}, {4, 3, 8} }
};

int formingMagicSquare(valarray< valarray<int> > &s) {
	valarray<int> sum;
	int cost = numeric_limits<int>::max();
	for (int i = 0; i < squares.size(); i++) {
		sum = abs(squares[i] - s).sum();
		cost = min(accumulate(begin(sum), end(sum), 0), cost);
	}
	return cost;
}

int main() {
	valarray< valarray<int> > s(valarray<int>(3), 3);
	for (int i = 0; i < s.size(); i++)
		for (int j = 0; j < s[i].size(); j++)
			cin >> s[i][j];
	cout << formingMagicSquare(s);
	return 0;
}