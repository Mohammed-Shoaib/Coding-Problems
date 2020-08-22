/*
Problem Statement: https://www.hackerrank.com/challenges/anagram/problem
*/

#include <iostream>
#include <string>

using namespace std;

int anagram(string s) {
	if(s.length()&1)
		return -1;
	size_t pos;
	int count = 0;
	string s1 = s.substr(0, s.length()/2);
	string s2 = s.substr(s.length()/2);
	for(int i=0 ; i<s1.length() ; i++){
		pos = s2.find(s1[i]);
		if(pos != string::npos)
			s2.erase(pos, 1);
		else
			count++;
	}
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
		cout<<anagram(s)<<endl;
	}
	return 0;
}