/*
Problem Statement: https://www.hackerrank.com/challenges/jumping-on-the-clouds-revisited/problem
*/

#include <iostream>
#include <vector>

using namespace std;

int jumpingOnClouds(vector<int> c, int k) {
	int e = 100;
	int i = 0;
	do{
		i = (i+k)%c.size();
		if(c[i])
			e -= 2;
		e -= 1;
	}while(i != 0);
	return e;
}

int main()
{
	int n, k, num;
	vector<int> c;
	cin>>n>>k;
	for(int i=0 ; i<n ; i++){
		cin>>num;
		c.push_back(num);
	}
	cout<<jumpingOnClouds(c, k);
	return 0;
}