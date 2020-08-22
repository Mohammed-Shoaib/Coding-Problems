/*
Problem Statement: https://www.hackerrank.com/challenges/strange-advertising/problem
*/

#include <iostream>

using namespace std;

int viralAdvertising(int n) {
	int r,l,c;
	r = 5;
	c = 0;
	for(int i=1 ; i<=n ; i++){
		l = r/2;
		r = l*3;
		c += l;
	}
	return c;
}

int main()
{
	int n;
	cin>>n;
	cout<<viralAdvertising(n);
	return 0;
}
