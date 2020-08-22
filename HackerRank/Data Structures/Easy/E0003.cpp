/*
Problem Code: https://www.hackerrank.com/challenges/dynamic-array/problem
*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N, Q, lastAnswer = 0;
	cin >> N >> Q;
	vector< vector<int> > seqList(N, vector<int>());
	while (Q--) {
		int t, x, y, pos, size;
		cin >> t >> x >> y;
		pos = (x ^ lastAnswer) % N;
		if (t == 1)
			seqList[pos].push_back(y);
		else {
			size = seqList[pos].size();
			lastAnswer = seqList[pos][y % size];
			cout << lastAnswer << endl;
		}
	}
	return 0;
}