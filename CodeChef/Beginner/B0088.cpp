// Problem Code: SIMDISH

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

string similarDishes(vector<string> A, vector<string> B) {
	int count = 0;
	unordered_set<string> set(A.begin(), A.end());
	for(int i=0 ; i<B.size() ; i++)
		if(set.find(B[i]) != set.end())
			count++;
	return (count >= 2) ? "similar" : "dissimilar";
}

int main(){
	int T;
	string s;
	vector<string> A(4), B(4);
	cin >> T;
	while(T--) {
		for(int i=0 ; i<4 ; i++) {
			cin >> s;
			A[i] = s;
		}
		for(int i=0 ; i<4 ; i++) {
			cin >> s;
			B[i] = s;
		}
		cout << similarDishes(A, B) << endl;
	}
	return 0;
}