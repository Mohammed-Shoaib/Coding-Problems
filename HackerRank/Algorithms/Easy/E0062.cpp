/*
Problem Statement: https://www.hackerrank.com/challenges/gem-stones/problem
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int gemstones(vector<string> arr) {
	string curr, last;
	for(size_t i=0 ; i<arr.size() ; i++)
		sort(arr[i].begin(), arr[i].end());
	last = arr[0];
	for(size_t i=1 ; i<arr.size() ; i++){
		set_intersection(last.begin(), last.end(), arr[i].begin(), arr[i].end(), back_inserter(curr));
		swap(last, curr);
		curr.clear();
	}
	return last.size();
}

int main()
{
	int n;
	string s;
	vector<string> arr;
	cin>>n;
	cin.ignore();
	for(int i=0 ; i<n ; i++){
		getline(cin, s);
		arr.push_back(s);
	}
	cout<<gemstones(arr);
	return 0;
}