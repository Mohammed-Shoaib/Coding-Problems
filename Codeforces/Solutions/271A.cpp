// Problem Code: 271A
 
#include <iostream>
#include <set>

using namespace std;

bool is_beautiful(int y) {
	set<int> seen;
	
	while (y) {
		if (seen.count(y % 10))
			return false;
		seen.insert(y % 10);
		y /= 10;
	}
	
	return true;
}

int beautiful_year(int y) {
	while (!is_beautiful(++y));
	return y;
}

int main() {
	int y;
	cin >> y;
	cout << beautiful_year(y);
	return 0;
}