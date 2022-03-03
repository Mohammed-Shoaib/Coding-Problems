// Problem Code: 96A
 
#include <iostream>
#include <string>

using namespace std;

string football(string s) {
	char last = '$';
	int limit = 7, cnt = 0;
	
	for (char& c: s) {
		if (c == last)
			cnt++;
		else
			cnt = 1;
		if (cnt == limit)
			return "YES";
		last = c;
	}
	
	return "NO";
}

int main() {
	string s;
	cin >> s;
	cout << football(s);
	return 0;
}