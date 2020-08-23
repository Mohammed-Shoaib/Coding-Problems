// Problem Code: MNMX

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

unsigned int minimumMaximum(vector<int> A) {
	unsigned int N, min;
	N = A.size() - 1;
	min = *min_element(A.begin(), A.end());
	return N*min;
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
		cout << minimumMaximum(A) << endl;
		A.clear();
	}
	return 0;
}