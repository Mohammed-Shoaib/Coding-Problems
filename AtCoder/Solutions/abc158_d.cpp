// Problem Code: abc158_d

#include <iostream>
#include <string>
#include <deque>
#include <algorithm>

using namespace std;

int main() {
	int Q;
	string S;
	bool flip = false;
	
	cin >> S >> Q;
	deque<char> D(S.begin(), S.end());
	
	while (Q--) {
		char C;
		int q, F;
		cin >> q;
		if (q == 1)
			flip = !flip;
		else {
			cin >> F >> C;
			if (--F ^ flip)
				D.push_back(C);
			else
				D.push_front(C);
		}
	}
	
	if (flip)
		reverse(D.begin(), D.end());
	
	for (char c: D)
		cout << c;
	
	return 0;
}