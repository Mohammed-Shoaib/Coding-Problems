/*
Problem Statement: https://www.hackerrank.com/challenges/beautiful-binary-string/problem
*/

#include <iostream>
#include <string>

using namespace std;

int beautifulBinaryString(string b) {
	string subB;
	int count = 0;
	for(int i=0 ; i<b.length()-2 ; i++){
		if(b[i] - '0')
			continue;
		subB = string() + b[i] + b[i+1] + b[i+2];
		if(!subB.compare("010")){
			count++;
			i += 2;
		}
	}
	return count;
}

int main()
{
	int n;
	string b;
	cin>>n;
	cin.ignore();
	getline(cin, b);
	cout<<beautifulBinaryString(b);
	return 0;
}