// Problem Code: CHEFARRP

#include <iostream>
#include <vector>

using namespace std;

int chefAndSubarrays(vector<int> A) {
	int count, sum, prod;
	count = A.size();
	for(int i=0 ; i<A.size()-1 ; i++) {
		sum = A[i];
		prod = A[i];
		for(int j=i+1 ; j<A.size() ; j++) {
			sum += A[j];
			prod *= A[j];
			if(sum == prod)
				count++;
		}
	}
	return count;
}

int main() {
	int T, n, num;
	vector<int> A;
	cin >> T;
	while(T--) {
		cin >> n;
		for(int i=0 ; i<n ; i++) {
			cin >> num;
			A.push_back(num);
		}
		cout << chefAndSubarrays(A) << endl;
		A.clear();
	}
	return 0;
}