// Problem Code: CNOTE

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

string chefAndNotebooks(int X, int Y, int K, vector<pair<int, int>> &notebooks){
	Y = X - Y;
	for(pair<int, int> &notebook : notebooks)
		if(notebook.first >= Y && notebook.second <= K)
			return "LuckyChef";
	return "UnluckyChef"; 
}

int main(){
	int T, X, Y, K, N, P, C;
	vector<pair<int, int>> notebooks;
	cin >> T;
	while(T--){
		cin >> X >> Y >> K >> N;
		for(int i=0 ; i<N ; i++){
			cin >> P >> C;
			notebooks.push_back(make_pair(P, C));
		}
		cout << chefAndNotebooks(X, Y, K, notebooks) << endl;
		notebooks.clear();
	}
	return 0;
}