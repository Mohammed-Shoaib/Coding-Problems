// Problem Code: AMSGAME1

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int subtractionGame(vector<int> A){
	int gcd = A[0];
	for(int i=1 ; i<A.size() ; i++)
		gcd = __gcd(A[i], gcd);
	return gcd;
}

int main(){
	int T, N, num;
	vector<int> A;
	cin >> T;
	while(T--){
		cin >> N;
		for(int i=0 ; i<N ; i++){
			cin >> num;
			A.push_back(num);
		}
		cout << subtractionGame(A) << endl;
		A.clear();
	}
	return 0;
}