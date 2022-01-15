// Problem Code: 1475B
 
#include <iostream>
#include <string>

using namespace std;

string new_years_number(int n) {
	int x = 2020, y = 2021;
	
	for (int i = 0; i <= n; i += x)
		if ((n - i) % y == 0)
			return "YES";
	
	return "NO";
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << new_years_number(n) << endl;
	}
	return 0;
}
