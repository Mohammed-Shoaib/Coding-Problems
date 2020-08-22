/*
Problem Statement: https://www.hackerrank.com/challenges/jumping-on-the-clouds/problem
*/

#include <iostream>
#include <vector>

using namespace std;

int jumpingOnClouds(vector<int> c) {
	int i, count;
	i = count = 0;
	while(i+2 < c.size()){
		if(c[i+2])
			i += 1;
		else
			i += 2;
		count++;
	}
	if(i != c.size()-1)
		count++;
	return count;
}

int main()
{
	int n, num;
	vector<int> c;
	cin>>n;
	for(int i=0 ; i<n ; i++){
		cin>>num;
		c.push_back(num);
	}
	cout<<jumpingOnClouds(c);
	return 0;
}
