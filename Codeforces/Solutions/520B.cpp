// Problem Code: 520B
 
#include <iostream>
#include <utility>

using namespace std;

int two_buttons(int n, int m) {
	int moves = 0;
	
	while (m != n) {
		moves++;
		if (m < n)
			moves += n - exchange(m, n) - 1;
		else if (m % 2 == 0)
			m /= 2;
		else
			m++;
	}
	
	return moves;
}

int main() {
	int n, m;
	cin >> n >> m;
	cout << two_buttons(n, m);
	return 0;
}
