/*
Problem Statement: https://www.hackerrank.com/challenges/manasa-and-stones/problem
*/

#include <iostream>
#include <set>
#include <vector>

using namespace std;

vector<int> stones(int n, int a, int b) {
	set<int> values;
	vector<int> results;
	for(int i=n-1, j=0 ; i>=0 ; i--, j++)
		values.insert(a*i + b*j);
	for(set<int>::iterator it=values.begin() ; it != values.end() ; it++)
			results.push_back(*it);
	return results;
}

int main()
{
	int T, n, a, b;
	vector<int> results;
	cin>>T;
	for(int i=1 ; i<=T ; i++){
		cin>>n>>a>>b;
		results = stones(n, a, b);
		for(int i=0 ; i<results.size() ; i++)
			cout<<results[i]<<" ";
		cout<<endl;
	}
	return 0;
}