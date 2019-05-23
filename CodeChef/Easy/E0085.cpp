// Problem Code: BINTREE

#include <iostream>

using namespace std;

int path(int i, int j) {
	int count = 0;
	while (i != j) {
		if (i > j)
			i >>= 1;
		else
			j >>= 1;
		count++;
	}
	return count;
}

int main() {
	int N;
	cin >> N;
	while (N--) {
		int i, j;
		cin >> i >> j;
		cout << path(i, j) << endl;
	}
	return 0;
}