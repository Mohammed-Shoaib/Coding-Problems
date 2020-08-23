// Problem Code: WALK

#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int walk(vector<int> &W) {
	int max = numeric_limits<int>::min();
	for(int i=0 ; i<W.size() ; i++)
		if(W[i] + i > max)
			max = W[i] + i;
	return max;
}

int main() {
	int T, N, num;
	vector<int> W;
	cin >> T;
	while(T--) {
		cin >> N;
		for(int i=0 ; i<N ; i++) {
			cin >> num;
			W.push_back(num);
		}
		cout << walk(W) << endl;
		W.clear();
	}
	return 0;
}