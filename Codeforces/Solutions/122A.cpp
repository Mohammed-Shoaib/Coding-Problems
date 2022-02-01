// Problem Code: 122A
 
#include <iostream>
#include <string>

using namespace std;

bool is_lucky(int n) {
	if (n == 0)
		return false;
	
	while (n) {
		if (n % 10 != 4 && n % 10 != 7)
			return false;
		n /= 10;	
	}
	
	return true;
}

string lucky_division(int n) {
	for (int i = 1; i <= n; i++)
		if (n % i == 0 && is_lucky(i))
			return "YES";
	return "NO";
}

int main() {
	int n;
	cin >> n;
	cout << lucky_division(n);
	return 0;
}