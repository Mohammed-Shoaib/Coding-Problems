/*
Problem Statement: https://www.hackerrank.com/challenges/mars-exploration/problem
*/

#include <iostream>
#include <string>

using namespace std;

int marsExploration(string s) {
	int count = 0;
	for(int i=0 ; i<s.length() ; i++){
		if((i+2)%3 == 0){
			if(s[i] != 'O')
				count++;
		}
		else if(s[i] != 'S')
			count++;
	}
	return count;
}

int main()
{
	string s;
	getline(cin, s);
	cout<<marsExploration(s);
	return 0;
}
