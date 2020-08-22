/*
Problem Statement: https://www.hackerrank.com/challenges/weighted-uniform-string/problem
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

vector<string> weightedUniformStrings(string s, vector<int> queries) {
	vector<string> results;
	unordered_set<int> weights;
	int weight = s[0] - 'a' + 1;
	weights.insert(weight);
	for(int i=1 ; i<s.size() ; i++){
		if(s[i] != s[i-1])
			weight = 0;
		weight += s[i] - 'a' + 1;
		weights.insert(weight);
	}
	for(int i=0 ; i<queries.size() ; i++){
		if(weights.find(queries[i]) != weights.end())
			results.push_back("Yes");
		else
			results.push_back("No");
	}
	return results;
}

int main()
{
	int n, num;
	string s;
	vector<int> x;
	vector<string> results;
	getline(cin, s);
	cin>>n;
	for(int i=0 ; i<n ; i++){
		cin>>num;
		x.push_back(num);
	}
	results = weightedUniformStrings(s, x);
	for(string &result : results)
		cout<<result<<endl;
	return 0;
}