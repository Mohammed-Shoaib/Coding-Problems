// Problem Code: RRCOPY

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int copyPaste(vector<int> &A){
	unordered_set<int> distinct(A.begin(), A.end());
	return distinct.size();
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
		cout << copyPaste(A) << endl;
		A.clear();
	}
	return 0;
}