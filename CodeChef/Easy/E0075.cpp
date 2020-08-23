// Problem Code: RRSUM

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void sumQueries(int N, vector<unsigned int> q) {
	unsigned int lower, upper, dist;
	lower = N + 2;
	upper = 3*N;
	for(int i=0 ; i<q.size() ; i++) {
		if(q[i] < lower || q[i] > upper)
			cout << 0 << endl;
		else {
			dist = min(q[i]-lower, upper-q[i]);
			cout << 1 + dist << endl;
		}
	}
}

int main() {
	int N, M;
	unsigned int num;
	vector<unsigned int> q;
	cin >> N >> M;
	while(M--) {
		cin >> num;
		q.push_back(num);
	}
	sumQueries(N, q);
	return 0;
}