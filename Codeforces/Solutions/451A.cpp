// Problem Code: 451A
 
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string game_with_sticks(int n, int m) {
	return (min(n, m) & 1) ? "Akshat" : "Malvika";
}

int main() {
	int n, m;
	cin >> n >> m;
	cout << game_with_sticks(n, m);
	return 0;
}