/*
Problem Statement: https://www.hackerrank.com/challenges/the-hurdle-race/problem
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int hurdleRace(int k, vector<int> height) {
	int diff = *max_element(height.begin(),height.end()) - k;
	return (diff>0) ? diff : 0;
}

int main()
{
	int n,k,num;
	vector<int> height;
	cin>>n>>k;
	for(int i=0 ; i<n ; i++){
		cin>>num;
		height.push_back(num);
	}
	cout<<hurdleRace(k,height);
	return 0;
}