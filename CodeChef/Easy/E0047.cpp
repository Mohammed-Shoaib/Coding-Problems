// Problem Code: SUBGCD

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int subarrayGCD(vector<int> &A) {
	int gcd = A[0];
	for(int i=1 ; i<A.size() && gcd != 1 ; i++)
		gcd = __gcd(A[i], gcd);
	return (gcd == 1) ? A.size() : -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T, N, num;
	vector<int> A;
	cin >> T;
	while(T--) {
		cin >> N;
		for(int i=0 ; i<N ; i++) {
			cin >> num;
			A.push_back(num);
		}
		cout << subarrayGCD(A) << endl;
		A.clear();
	}
	return 0;
}