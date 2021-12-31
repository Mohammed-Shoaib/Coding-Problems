// Problem Code: 4C
 
#include <iostream>
#include <string>
#include <map>

using namespace std;

string registration_system(string s, map<string, int>& seen) {
	if (!seen.count(s)) {
		seen[s] = 0;
		return "OK";
	}
	s += to_string(++seen[s]);
	return s;
}

int main() {
	int n;
	map<string, int> seen;
	cin >> n;
	while (n--) {
		string s;
		cin >> s;
		cout << registration_system(s, seen) << endl;
	}
	return 0;
}