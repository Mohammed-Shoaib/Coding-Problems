/*
Problem Statement: https://www.hackerrank.com/challenges/utopian-tree/problem
*/

#include <iostream>
#include <cmath>

using namespace std;

int utopianTree(int n) {
	int num = pow(2,ceil(n/2.0)+1);
	return (n&1)?(num-2):(num-1);
}

int main()
{
	int t,n;
	cin>>t;
	for(int i=1 ; i<=t ; i++){
		cin>>n;
		cout<<utopianTree(n)<<endl;
	}
	return 0;
}
