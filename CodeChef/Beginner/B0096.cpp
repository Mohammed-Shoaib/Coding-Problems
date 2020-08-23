// Problem Code: HOWMANY

#include <iostream>
#include <string>

using namespace std;

string howMany(int N) {
	int d = to_string(N).size();
	if (d == 1)
		return "1";
	else if (d == 2)
		return "2";
	else if (d == 3)
		return "3";
	else
		return "More than 3 digits";
}

int main() {
	int N;
	cin >> N;
	cout << howMany(N);
	return 0;
}