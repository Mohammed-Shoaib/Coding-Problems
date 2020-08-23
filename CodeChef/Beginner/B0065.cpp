// Problem Code: STRPALIN

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string palindromicSubstring(string A, string B) {
	for(int i=0 ; i<A.length() ; i++)
		for(int j=0 ; j<B.length() ; j++)
			if(A[i] == B[j])
				return "Yes";
	return "No";
}

int main() {
	int T;
	string A, B;
	cin >> T;
	while(T--) {
		cin >> A >> B;
		cout << palindromicSubstring(A, B) << endl;
	}
	return 0;
}