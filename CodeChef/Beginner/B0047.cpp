// Problem Code: MISSP

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int chefAndDolls(vector<int> A) {
	int doll;
	unordered_map<int, int> map;
	for(int i=0 ; i<A.size() ; i++)
		map[A[i]]++;
	for(unordered_map<int, int>::iterator it = map.begin() ; it != map.end() ; it++)
		if(it->second & 1){
			doll = it->first;
			break;
		}
	return doll;
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
		cout << chefAndDolls(A) << endl;
		A.clear();
	}
	return 0;
}