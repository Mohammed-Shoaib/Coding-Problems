/*
Problem Statement: https://www.hackerrank.com/challenges/counting-valleys/problem
*/

#include <iostream>
#include <string>

using namespace std;

int countingValleys(int n, string s) {
	int count,totalValleys;
	bool valleyStarted = false;
	count = totalValleys = 0;
	for(int i=0 ; i<s.length() ; i++){
		if(s[i] == 'U')
			count++;
		else
			count--;
		if(!valleyStarted && count < 0)
			totalValleys++;
		if(!valleyStarted && count<0)
			valleyStarted = true;
		else if(valleyStarted && count>=0)
			valleyStarted = false;
	}
	return totalValleys;
}

int main()
{
	int n;
	string s;
	cin>>n;
	cin.ignore();
	getline(cin,s);
	cout<<countingValleys(n,s);
	return 0;
}
