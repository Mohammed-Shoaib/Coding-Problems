// Problem Code: abc170_e

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <functional>

using namespace std;

const int limit = 2 * 1e5;

void smart_infants(int N, int Q, vector<int>& A, vector<int>& B) {
	multiset<int> even;
	vector<multiset<int, greater<int>>> kg(limit + 1);

	for (int i = 1; i <= N; i++)
		kg[B[i]].insert(A[i]);
	
	for (int i = 0; i <= limit; i++)
		if (!kg[i].empty())
			even.insert(*kg[i].begin());
	
	while (Q--) {
		int c, d;
		cin >> c >> d;

		// delete from the original position
		even.erase(even.find(*kg[B[c]].begin()));
		kg[B[c]].erase(kg[B[c]].find(A[c]));
		if (!kg[B[c]].empty())
			even.insert(*kg[B[c]].begin());
		
		// insert into the new position
		B[c] = d;
		if (!kg[B[c]].empty())
			even.erase(even.find(*kg[B[c]].begin()));
		kg[B[c]].insert(A[c]);
		even.insert(*kg[B[c]].begin());
		
		cout << *even.begin() << endl;
	}
}

int main() {
	int N, Q;
	cin >> N >> Q;
	vector<int> A(N + 1), B(limit + 1);
	for (int i = 1; i <= N; i++)
		cin >> A[i] >> B[i];
	smart_infants(N, Q, A, B);
	return 0;
}