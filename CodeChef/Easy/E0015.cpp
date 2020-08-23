// Problem Code: ERROR

#include <iostream>
#include <string>

using namespace std;

string feedback(string S){
	if(S.find("101") != string::npos || S.find("010") != string::npos)
		return "Good";
	else
		return "Bad";
}

int main()
{
	int T;
	string S;
	cin >> T;
	cin.ignore();
	for(int i=1 ; i<=T ; i++){
		getline(cin, S);
		cout << feedback(S) << endl;
	}
	return 0;
}