// Problem Code: CHN09

#include <iostream>
#include <string>

using namespace std;

int minimumBalloons(string s) {
	int a, b;
	a = b = 0;
	for(int i=0 ; i<s.length() ; i++)
		(s[i] == 'a') ? a++ : b++;
	return (a < b) ? a : b;
}

int main() {
	int T;
	string s;
	cin >> T;
	while(T--) {
		cin >> s;
		cout << minimumBalloons(s) << endl;
	}
	return 0;
}