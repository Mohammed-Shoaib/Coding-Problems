/*
Problem Statement: https://www.hackerrank.com/challenges/kaprekar-numbers/problem
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

bool checkIfKaprekarNumber(int n){
	int l,r,d;
	long nSquare;
	nSquare = pow(n,2);
	d = to_string(n).length();
	string s = to_string(nSquare);
	r = stoi(s.substr(s.length()-d,d));
	s = s.substr(0,s.length()-d);
	if(s.empty())
		l = 0;
	else
		l = stoi(s);
	if(l+r == n)
		return true;
	return false;
}

void kaprekarNumbers(int p, int q) {
	vector<int> values;
	for(int i=p ; i<=q ; i++)
		if(checkIfKaprekarNumber(i))
			values.push_back(i);
	for(int value:values)
		cout<<value<<" ";
	if(!values.size())
		cout<<"INVALID RANGE"<<endl;
}

int main()
{
	int p,q;
	cin>>p>>q;
	kaprekarNumbers(p,q);
	return 0;
}
