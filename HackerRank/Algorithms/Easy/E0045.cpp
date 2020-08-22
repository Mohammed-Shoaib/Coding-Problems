/*
Problem Statement: https://www.hackerrank.com/challenges/happy-ladybugs/problem
*/

#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

string happyLadybugs(string b) {
	vector<pair<char, int>> count;
	bool isUnderscore = (b.find('_') != b.npos) ? true : false;
	if(isUnderscore){
		for(int i=0 ; i<b.length() ; i++){
			bool isFound = false;
			if(b[i] == '_')
				continue;
			for(int j=0 ; j<count.size() ; j++)
				if(b[i] == count[j].first){
					count[j].second++;
					isFound = true;
					break;
				}
			if(!isFound)
				count.push_back(make_pair(b[i], 1));
		}
		for(int i=0 ; i<count.size() ; i++)
			if(count[i].second == 1)
				return "NO";
		return "YES";
	}else{
		if(b.length() == 1 || b[b.length()-1] != b[b.length()-2])
			return "NO";
		for(int i=1 ; i<b.length()-1 ; i+=2)
			if(b[i-1] != b[i] && b[i+1] != b[i])
				return "NO";
		return "YES";
	}
}

int main()
{
	int g, n;
	string b;
	cin>>g;
	for(int i=1 ; i<=g ; i++){
		cin>>n;
		cin.ignore();
		getline(cin, b);
		cout<<happyLadybugs(b)<<endl;
	}
	return 0;
}