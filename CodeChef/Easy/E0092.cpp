// Problem Code: GUESSNUM

#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>

using namespace std;

vector<long long> guess_the_number(long long A, long long M) {
	set<long long> values;
	unordered_set<long long> div;

	// Store all divisors of M
	for (long long i = 1; i * i <= M; i++)
		if (M % i == 0)
			div.insert({i, M / i});
	
	// Store possibles values of N
	for (long long d: div) {
		long long q = (M / d) - 1;
		if (q && q % A == 0)
			values.insert(d * (q / A));
	}

	// Remove duplicates and return as sorted
	return vector<long long>(values.begin(), values.end());
}

int main() {
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		long long A, M;
		vector<long long> res;
		cin >> A >> M;
		res = guess_the_number(A, M);
		cout << res.size() << endl;
		for (int i = 0; i < res.size(); i++)
			cout << res[i] << " ";
		cout << endl;
	}
	return 0;
}