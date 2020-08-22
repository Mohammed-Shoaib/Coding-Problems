/*
Problem Statement: https://www.hackerrank.com/challenges/equality-in-a-array/problem
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int equalizeArray(vector<int> arr) {
	int max = 0;
	unordered_map<int,int> umap;
	for(int a:arr)
		umap[a]++;
	for(auto itr=umap.begin() ; itr != umap.end() ; ++itr)
		if(itr->second > max)
			max = itr->second;
	return arr.size()-max;
}

int main()
{
	int n,num;
	vector<int> arr;
	cin>>n;
	for(int i=0 ; i<n ; i++){
		cin>>num;
		arr.push_back(num);
	}
	cout<<equalizeArray(arr);
	return 0;
}