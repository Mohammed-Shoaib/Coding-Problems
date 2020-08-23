// Problem Code: STICKS

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int sticks(vector<int> A) {
	vector<int> sides;
	unordered_set<int> set;
	unordered_set<int>::iterator it;
	for(int i=0 ; i<A.size() ; i++) {
		it = set.find(A[i]);
		if(it != set.end()) {
			sides.push_back(A[i]);
			set.erase(it);
		}
		else
			set.insert(A[i]);
	}
	if(sides.size() < 2)
		return -1;
	sort(sides.rbegin(), sides.rend());
	return sides[0]*sides[1];
}

int main() {
	int T, N, num;
	vector<int> A;
	cin >> T;
	while(T--) {
		cin >> N;
		for(int i=0 ; i<N ; i++) {
			cin >> num;
			A.push_back(num);
		}
		cout << sticks(A) << endl;
		A.clear();
	}
	return 0;
}