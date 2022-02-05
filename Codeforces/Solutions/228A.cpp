// Problem Code: 228A
 
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int is_your_horseshoe_on_the_other_hoof(vector<int>& s) {
	set<int> seen(s.begin(), s.end());
	return s.size() - seen.size();
}

int main() {
	vector<int> s(4);
	for (int& x: s)
		cin >> x;
	cout << is_your_horseshoe_on_the_other_hoof(s);
	return 0;
}