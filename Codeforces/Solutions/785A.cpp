// Problem Code: 785A
 
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int anton_and_polyhedrons(int n, vector<string>& s) {
	int faces = 0;
	unordered_map<char, int> mp = {
		{'T', 4}, {'C', 6}, {'O', 8}, {'D', 12}, {'I', 20}
	};
	
	for (int i = 0; i < n; i++)
		faces += mp[s[i][0]];
	
	return faces;
}

int main() {
	int n;
	cin >> n;
	vector<string> s(n);
	for (int i = 0; i < n; i++)
		cin >> s[i];
	cout << anton_and_polyhedrons(n, s);
	return 0;
}