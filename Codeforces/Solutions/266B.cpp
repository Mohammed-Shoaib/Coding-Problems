// Problem Code: 266B
 
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string queue_at_the_school(int n, int t, string s) {
	while (t--) {
		for (int i = 0; i + 1 < n; i++)
			if (s[i] == 'B' && s[i + 1] == 'G') {
				swap(s[i], s[i + 1]);
				i++;
			}
	}
	
	return s;
}

int main() {
	int n, t;
	string s;
	cin >> n >> t >> s;
	cout << queue_at_the_school(n, t, s);
	return 0;
}