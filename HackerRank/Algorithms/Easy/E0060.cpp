/*
Problem Statement: https://www.hackerrank.com/challenges/string-construction/problem
*/

#include <iostream>
#include <string>
#include <set>

using namespace std;

int stringConstruction(string s) {
	return set<char>(s.begin(), s.end()).size();
}

int main()
{
	int n;
	string s;
	cin>>n;
	cin.ignore();
	for(int i=1 ; i<=n ; i++){
		getline(cin, s);
		cout<<stringConstruction(s)<<endl;
	}
	return 0;
}