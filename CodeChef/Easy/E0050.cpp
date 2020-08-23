// Problem Code: NOCODING

#include <iostream>
#include <cmath>

using namespace std;

string codeCrazyMinions(string W) {
	int total = 2;
	for(int i=1 ; i<W.size() ; i++)
		total += (W[i]-W[i-1] + 26) % 26 + 1;
	return (total <= W.length()*11) ? "YES" : "NO";
}

int main() {
	int T;
	string W;
	cin >> T;
	while(T--) {
		cin >> W;
		cout << codeCrazyMinions(W) << endl;
	}
	return 0;
}