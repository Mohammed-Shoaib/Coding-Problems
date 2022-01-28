// Problem Code: 1520B
 
#include <iostream>

using namespace std;

int get_length(int n) {
	int len = 0;
	while (n) {
		n /= 10;
		len++;
	}
	return len;
}

int generate_length(int x, int len) {
	int num = 0;
	while (len--) {
		num *= 10;
		num += x;
	}
	return num;
}

int ordinary_numbers(int n) {
	int cnt, len;
	len = get_length(n);
	cnt = 9 * (len - 1);
	
	for (int i = 1; generate_length(i, len) <= n; i++)
		cnt++;
	
	return cnt;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << ordinary_numbers(n) << endl;
	}
	return 0;
}
