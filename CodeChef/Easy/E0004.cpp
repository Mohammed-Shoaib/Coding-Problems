// Problem Code: HORSES

#include <iostream>
#include <vector>
#include <limits>
#include <cmath>
#include <algorithm>

using namespace std;

int findHorses(vector<int> S){
	int min = numeric_limits<int>::max();
	sort(S.begin(), S.end());
	for(int i=0 ; i<S.size()-1 ; i++)
		if(abs(S[i] - S[i+1]) < min)
			min = abs(S[i] - S[i+1]);
	return min;
}

int main()
{
	int T, N, num;
	vector<int> S;
	cin >> T;
	for(int i=1 ; i<=T ; i++){
		cin >> N;
		for(int j=0 ; j<N ; j++){
			cin >> num;
			S.push_back(num);
		}
		cout << findHorses(S) << endl;
		S.clear();
	}
	return 0;
}