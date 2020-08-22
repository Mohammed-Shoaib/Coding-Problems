/*
Problem Statement: https://www.hackerrank.com/challenges/larrys-array/problem
*/

#include <iostream>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

string larrysArray(vector<int> A) {
	vector<int> count(A.size()-1);
	for(int i=0 ; i<A.size()-1 ; i++)
		for(int j=i+1 ; j<A.size() ; j++)
			if(A[j] < A[i])
				count[i]++;
	int sum = accumulate(count.begin(), count.end(), 0);
	return (sum & 1) ? "NO" : "YES";
}

int main()
{
	int t, n, num;
	vector<int> A;
	cin>>t;
	for(int i=1 ; i<=t ; i++){
		cin>>n;
		for(int j=0 ; j<n ; j++){
			cin>>num;
			A.push_back(num);
		}
		cout<<larrysArray(A)<<endl;
		A.clear();
	}
	return 0;
}