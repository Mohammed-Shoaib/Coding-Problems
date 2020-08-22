/*
Problem Statement: https://www.hackerrank.com/challenges/kangaroo/problem
*/

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

string kangaroo(int x1, int v1, int x2, int v2) {
	if(v1-v2 == 0)
		return (x2-x1 == 0) ? "YES" : "NO";
	float result = (float)(x2-x1)/(v1-v2);
	if(result > 0)
		return (result == floor(result)) ? "YES" : "NO";
	return "NO";
}

int main()
{
	int x1,v1,x2,v2;
	cin>>x1>>v1>>x2>>v2;
	cout<<kangaroo(x1,v1,x2,v2);
	return 0;
}