/*
Problem Statement: https://www.hackerrank.com/challenges/two-strings/problem
*/

#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

string twoStrings(string s1, string s2) {
	unordered_set<char> s(s1.begin(), s1.end());
	for(char &c : s2)
		if(s.find(c) != s.end())
			return "YES";
	return "NO";
}

int main()
{
	int n;
	string s1, s2;
	cin>>n;
	cin.ignore();
	for(int i=1 ; i<=n ; i++){
		getline(cin, s1);
		getline(cin, s2);
		cout<<twoStrings(s1, s2)<<endl;
	}
	return 0;
}