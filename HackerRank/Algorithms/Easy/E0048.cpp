/*
Problem Statement: https://www.hackerrank.com/challenges/hackerrank-in-a-string/problem
*/

#include <iostream>
#include <string>

using namespace std;

string hackerrankInString(string s) {
	int i, j;
	string s2 = "hackerrank";
	for(i=0, j=0 ; i<s.length() && j<s2.length() ; i++)
		if(s[i] == s2[j])
			j++;
	return (j == s2.length()) ? "YES" : "NO";
}

int main()
{
	int q;
	string s;
	cin>>q;
	cin.ignore();
	for(int i=1 ; i<=q ; i++){
		getline(cin, s);
		cout<<hackerrankInString(s)<<endl;
	}
	return 0;
}