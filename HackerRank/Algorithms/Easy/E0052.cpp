/*
Problem Statement: https://www.hackerrank.com/challenges/the-love-letter-mystery/problem
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int theLoveLetterMystery(string s) {
	int count = 0;
	for(int i=0, j=s.length()-1 ; i<s.length()/2 ; i++, j--)
		count += abs(s[i] - s[j]);
	return count;
}

int main()
{
	int q;
	string s;
	cin>>q;
	cin.ignore();
	for(int i=1 ; i<=q ; i++){
		getline(cin, s);
		cout<<theLoveLetterMystery(s)<<endl;
	}
	return 0;
}