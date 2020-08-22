/*
Problem Statement: https://www.hackerrank.com/challenges/cats-and-a-mouse/problem
*/

#include <iostream>
#include <cmath>

using namespace std;

string catAndMouse(int x, int y, int z) {
	int diffA,diffB;
	diffA = abs(x-z);
	diffB = abs(y-z);
	if(diffA<diffB)
		return "Cat A";
	else if(diffA>diffB)
		return "Cat B";
	else
		return "Mouse C";
}

int main()
{
	int q,x,y,z;
	cin>>q;
	for(int i=1 ; i<=q ; i++){
		cin>>x>>y>>z;
		cout<<catAndMouse(x,y,z)<<endl;
	}
	return 0;
}