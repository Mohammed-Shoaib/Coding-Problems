/*
Problem Statement: https://www.hackerrank.com/challenges/absolute-permutation/problem
*/

#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>

using namespace std;

vector<int> absolutePermutation(int n, int k) {
	vector<int> absPerm(n);
	if(k == 0){
		iota(absPerm.begin(), absPerm.end(), 1);
		return absPerm;
	}
	if(n%(2*k) != 0)
		return vector<int>({-1});
	for(int i=1 ; i<=n ; i++){
		if( (i-1) % k == (i-1) % (2*k) )
			absPerm[i-1] = i+k;
		else
			absPerm[i-1] = abs(i-k);
	}
	return absPerm;
}

int main()
{
	int t, n, k;
	vector<int> absPerm;
	cin>>t;
	for(int i=1 ; i<=t ; i++){
		cin>>n>>k;
		absPerm = absolutePermutation(n, k);
		for(int i=0 ; i<absPerm.size() ; i++)
			cout<<absPerm[i]<<" ";
		cout<<endl;
	}
	return 0;
}