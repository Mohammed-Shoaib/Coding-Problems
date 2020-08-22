/*
Problem Statement: https://www.hackerrank.com/challenges/taum-and-bday/problem
*/

#include <iostream>

using namespace std;

long taumBday(int b, int w, int bc, int wc, int z) {
	if(bc > wc+z)
		bc = wc+z;
	else if(wc > bc+z)
		wc = bc+z;
	return (long)b*bc + (long)w*wc;
}

int main()
{
	int t;
	cin>>t;
	for(int i=1 ; i<=t ; i++){
		int b,w,bc,wc,z;
		cin>>b>>w>>bc>>wc>>z;
		cout<<taumBday(b,w,bc,wc,z)<<endl;
	}
	return 0;
}