// Problem Code: SUBINC

#include <iostream>
#include <vector>

using namespace std;

long countSubarrays(vector<int> A) {
	long length, count;
	count = 0;
	length = 1;
	for(int i=0 ; i<A.size()-1 ; i++, length++)
		if(A[i] > A[i+1]) {
			count += length*(length+1)/2;
			length = 0;
		}
	count += length*(length+1)/2;
	return count;
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
		cout << countSubarrays(A) << endl;
		A.clear();
	}
	return 0;
}