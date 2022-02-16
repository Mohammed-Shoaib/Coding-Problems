// Problem Code: 266A
 
#include <iostream>
#include <string>
#include <utility>

using namespace std;

int stones_on_the_table(int n, string s) {
	int cnt = 0;
	char last = '$';
	
	for (char& c: s)
		cnt += (c == exchange(last, c));
	
	return cnt;
}

int main() {
	int n;
	string s;
	cin >> n >> s;
	cout << stones_on_the_table(n, s);
	return 0;
}