// Problem Code: 1331C

#include <iostream>
#include <bitset>

using namespace std;

const int M = 6;

void swap(int u, int v, bitset<M>& b) {
	bool temp = b[u];
	b[u] = b[v];
	b[v] = temp;
}

int permute(int a) {
	bitset<M> b(a);
	swap(0, 4, b);
	swap(2, 3, b);
	return b.to_ulong();
}

int main() {
	int a;
	cin >> a;
	cout << permute(a);
	return 0;
}