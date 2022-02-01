// Problem Code: 133A
 
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

string hq9plus(string p) {
	unordered_set<char> seen = {'H', 'Q', '9'};
	for (char& c: p)
		if (seen.count(c))
			return "YES";
	return "NO";
}

int main() {
	string p;
	cin >> p;
	cout << hq9plus(p);
	return 0;
}