// Problem Code: BUYING2

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int buyingSweets(int X, vector<int> A){
	int sum = accumulate(A.begin(), A.end(), 0);
	for(int i=0 ; i<A.size() ; i++)
		if(A[i] <= sum%X)
			return -1;
	return sum/X;
}

int main()
{
	int T, N, X, num;
	vector<int> A;
	cin >> T;
	for(int i=1 ; i<=T ; i++){
		cin >> N >> X;
		for(int j=0 ; j<N ; j++){
			cin >> num;
			A.push_back(num);
		}
		cout << buyingSweets(X, A) << endl;
		A.clear();
	}
	return 0;
}