/*
Problem Statement: https://www.hackerrank.com/challenges/picking-numbers/problem
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int pickingNumbers(vector<int> a) {
	int max = 0;
	vector<int> freq(100);
	for(int i=0 ; i<a.size() ; i++)
		freq[a[i]]++;
	for(int i=0 ; i<freq.size()-1 ; i++)
		if(freq[i] + freq[i+1] > max)
			max = freq[i] + freq[i+1];
	return max;
}

int main()
{
	int n, num;
	vector<int> a;
	cin>>n;
	for(int i=0 ; i<n ; i++){
		cin>>num;
		a.push_back(num);
	}
	cout<<pickingNumbers(a);
	return 0;
}