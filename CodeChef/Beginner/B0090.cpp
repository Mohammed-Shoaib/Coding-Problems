// Problem Code: UTMOPR

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

string strangeOperations(int K, vector<int> A) {
	int sum = accumulate(A.begin(), A.end(), 0);
	if(sum % 2)
		return "even";
	return (K == 1) ? "odd" : "even";
}

int main(){
	int T, N, K, num;
	vector<int> A;
	cin >> T;
	while(T--) {
		cin >> N >> K;
		for(int i=0 ; i<N ; i++) {
			cin >> num;
			A.push_back(num);
		}
		cout << strangeOperations(K, A) << endl;
		A.clear();
	}
	return 0;
}