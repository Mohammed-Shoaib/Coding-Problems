// Problem Code: 58A
 
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string chat_room(string s) {
	vector<char> v = {'o', 'l', 'l', 'e', 'h'};
	
	for (char& c: s) {
		if (c == v.back())
			v.pop_back();
		if (v.empty())
			return "YES";
	}
	
	return "NO";
}

int main() {
	string s;
	cin >> s;
	cout << chat_room(s);
	return 0;
}