// Problem Code: 1056B

#include <iostream>
#include <vector>

using namespace std;

long long divide_candies(long long n, int m) {
	long long candies = 0;
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= m; j++)
			if ((i * i + j * j) % m == 0)
				candies += ((n - i + m) / m) * ((n - j + m) / m);
	return candies;
}

int main() {
	int n, m;
	cin >> n >> m;
	cout << divide_candies(n, m);
	return 0;
}