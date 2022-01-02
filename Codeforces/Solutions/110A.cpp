// Problem Code: 110A
 
#include <iostream>

using namespace std;

bool is_lucky_number(int n) {
	while (n) {
		if (n % 10 != 4 && n % 10 != 7)
			return false;
		n /= 10;
	}
	return true;
}

string nearly_lucky_number(int64_t n) {
	int cnt = 0;
	while (n) {
		cnt += (n % 10 == 4 || n % 10 == 7);
		n /= 10;
	}
	return cnt && is_lucky_number(cnt) ? "YES" : "NO";
}

int main() {
	int64_t n;
	cin >> n;
	cout << nearly_lucky_number(n);
	return 0;
}