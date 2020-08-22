/*
Problem Statement: https://www.hackerrank.com/challenges/cut-the-sticks/problem
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> cutTheSticks(vector<int> arr) {
	vector<int> values;
	while(arr.size() != 0){
		values.push_back(arr.size());
		int min = *min_element(arr.begin(),arr.end());
		arr.erase(remove(arr.begin(),arr.end(),min),arr.end());
	}
	return values;
}

int main()
{
	int n,num;
	vector<int> a,values;
	cin>>n;
	for(int i=0 ; i<n ; i++){
		cin>>num;
		a.push_back(num);
	}
	values = cutTheSticks(a);
	for(int value:values)
		cout<<value<<endl;
	return 0;
}