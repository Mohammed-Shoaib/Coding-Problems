/*
Problem Statement: https://www.hackerrank.com/challenges/non-divisible-subset/problem
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int nonDivisibleSubset(int k, vector<int> S) {
	int count = 0;
	vector<int> freq(k);
	for(int i=0 ; i<S.size() ; i++)
		freq[S[i]%k]++;
	if(k%2 == 0)
		freq[k/2] = min(freq[k/2], 1);
	count += min(freq[0], 1);
	for(int i=1 ; i<=k/2 ; i++)
		count += max(freq[i], freq[k-i]);
	return count;
}

int main()
{
	int n, k, num;
	vector<int> S;
	cin>>n>>k;
	for(int i=0 ; i<n ; i++){
		cin>>num;
		S.push_back(num);
	}
	cout<<nonDivisibleSubset(k, S);
	return 0;
}