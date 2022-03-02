// Problem Code: 734A
 
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string anton_and_danik(string s) {
	int cnt_a, cnt_d;
	cnt_a = count(s.begin(), s.end(), 'A');
	cnt_d = count(s.begin(), s.end(), 'D');
	
	if (cnt_a == cnt_d)
		return "Friendship";
	else if (cnt_a > cnt_d)
		return "Anton";
	else
		return "Danik";
}

int main() {
	int n;
	string s;
	cin >> n >> s;
	cout << anton_and_danik(s);
	return 0;
}