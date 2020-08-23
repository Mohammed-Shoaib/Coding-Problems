// Problem Code: SALARY

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int minimumNumberOfMoves(vector<int> W){
	int min = *min_element(W.begin(), W.end());
	for(int &w : W)
		w -= min;
	return accumulate(W.begin(), W.end(), 0);
}

int main(){
	int T, N, num;
	vector<int> W;
	cin >> T;
	while(T--){
		cin >> N;
		for(int i=0 ; i<N ; i++){
			cin >> num;
			W.push_back(num);
		}
		cout << minimumNumberOfMoves(W) << endl;
		W.clear();
	}
	return 0;
}