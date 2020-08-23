// Problem Code: MAXDIFF

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std;

int maximumDifference(int K, vector<int> W){
	int son, chef;
	sort(W.begin(), W.end());
	if(K > W.size()/2)
		K = W.size() - K;
	son = accumulate(W.begin(), W.begin()+K, 0);
	chef = accumulate(W.begin()+K, W.end(), 0);
	return chef-son;
}

int main()
{
	int T, N, K, num;
	vector<int> W;
	cin >> T;
	for(int i=1 ; i<=T ; i++){
		cin >> N >> K;
		for(int j=0 ; j<N ; j++){
			cin >> num;
			W.push_back(num);
		}
		cout << maximumDifference(K, W) << endl;
		W.clear();
	}
	return 0;
}