// Problem Code: ONP

#include <iostream>
#include <ctype.h>
#include <string>
#include <stack>

using namespace std;

string transformTheExpression(string s){
	string rpn;
	stack<char> operators;
	for(int i=0 ; i<s.size() ; i++){
		if(isalpha(s[i]))
			rpn += s[i];
		else if(s[i] == '(')
			continue;
		else if(s[i] == ')'){
			rpn += operators.top();
			operators.pop();
		}
		else
			operators.push(s[i]);
	}
	return rpn;
}

int main()
{
	int T;
	string s;
	cin >> T;
	cin.ignore();
	for(int i=1 ; i<=T ; i++){
		getline(cin, s);
		cout << transformTheExpression(s) << endl; 
	}
	return 0;
}