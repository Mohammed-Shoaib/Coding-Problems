/*
Problem Statement: https://www.hackerrank.com/challenges/encryption/problem
*/

#include <iostream>
#include <cmath>

using namespace std;

string encryption(string s) {
	string result;
	int rows = floor(sqrt(s.length()));
	int columns = ceil(sqrt(s.length()));
	if(rows*columns < s.length())
		rows++;
	for(int i=0, k=0 ; i<columns ; i++){
		for(int j=i ; j<s.length() ; j += columns)
			result += s[j];
		result += ' ';
	}
	return result;
}

int main()
{
	string s;
	getline(cin, s);
	cout<<encryption(s);
	return 0;
}