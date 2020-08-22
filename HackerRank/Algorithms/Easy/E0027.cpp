/*
Problem Statement: https://www.hackerrank.com/challenges/repeated-string/problem
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

long repeatedString(string s, long n) {
	long total = count(s.begin(),s.end(),'a');
	total *= n/s.length();
	total += count(s.begin(),s.begin()+(n%s.length()),'a');
	return total;
}

int main()
{
	long n;
	string s;
	getline(cin,s);
	cin>>n;
	cout<<repeatedString(s,n);
	return 0;
}
