// Problem Code: LCH15JAB

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

string pieceOfCake(string S) {
	int max, sum;
	vector<int> count(26);
	for(int i=0 ; i<S.length() ; i++)
		count[S[i]-'a']++;
	max = *max_element(count.begin(), count.end());
	sum = accumulate(count.begin(), count.end(), 0) - max;
	return (max == sum) ? "YES" : "NO";
}

int main() {
	int T;
	string S;
	cin >> T;
	while(T--) {
		cin >> S;
		cout << pieceOfCake(S) << endl;
	}
	return 0;
}