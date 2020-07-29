/*
Problem Statement: https://www.facebook.com/codingcompetitions/hacker-cup/2020/qualification-round/problems/B
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

char alchemy(int N, string& C) {
	int bal = 0;
	for(char& c: C)
		bal += 2 * (c == 'A') - 1;
	return (abs(bal) == 1) ? 'Y' : 'N';
}

int main() {
	int T;
	cin >> T;
	for (int x = 1; x <= T; x++) {
		int N;
		string C;
		cin >> N >> C;
		cout << "Case #" << x << ": " << alchemy(N, C) << endl;
	}
	return 0;
}