/*
Problem Statement: https://www.hackerrank.com/challenges/apple-and-orange/problem
*/

#include <iostream>
#include <vector>

using namespace std;

void countApplesAndOranges(int s, int t, int a, int b, vector<int> apples, vector<int> oranges) {
	int appleCount,orangeCount;
	appleCount = orangeCount = 0;
	for(int i=0 ; i<apples.size() ; i++)
		if((a + apples[i] >= s) && (a + apples[i] <= t))
			appleCount++;
	for(int i=0 ; i<oranges.size() ; i++)
		if((b + oranges[i] >= s) && (b + oranges[i] <= t))
			orangeCount++;
	cout<<appleCount<<endl;
	cout<<orangeCount<<endl;
}

int main()
{
	int s,t,a,b,m,n,num;
	vector<int> apples,oranges;
	cin>>s>>t;
	cin>>a>>b;
	cin>>m>>n;
	for(int i=0 ; i<m ; i++){
		cin>>num;
		apples.push_back(num);
	}
	for(int i=0 ; i<n ; i++){
		cin>>num;
		oranges.push_back(num);
	}
	countApplesAndOranges(s,t,a,b,apples,oranges);
	return 0;
}