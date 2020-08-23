// Problem Code: COLOR

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int chefAndColoring(string S) {
	int maxColor, r, g, b;
	r = g = b = 0;
	for(int i=0 ; i<S.length() ; i++) {
		if(S[i] == 'R')
			r++;
		else if(S[i] == 'G')
			g++;
		else
			b++;
	}
	maxColor = max(b, max(r, g));
	return (r+g+b) - maxColor;
}

int main() {
	int T, N;
	string S;
	cin >> T;
	while(T--) {
		cin >> N >> S;
		cout <<chefAndColoring(S) << endl;
	}
	return 0;
}