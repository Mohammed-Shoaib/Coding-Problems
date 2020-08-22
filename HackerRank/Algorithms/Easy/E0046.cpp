/*
Problem Statement: https://www.hackerrank.com/challenges/sock-merchant/problem
*/

#include <iostream>
#include <vector>
#include <set>

using namespace std;

int sockMerchant(int n, vector<int> ar) {
	set<int> socks;
	set<int>::iterator it;
	int count = 0;
	for(int i=0 ; i<ar.size() ; i++){
		it = socks.find(ar[i]);
		if(it != socks.end()){
			count++;
			socks.erase(it);
		}
		else
			socks.insert(ar[i]);
	}
	return count;
}

int main()
{
	int n, num;
	vector<int> ar;
	cin>>n;
	for(int i=0 ; i<n ; i++){
		cin>>num;
		ar.push_back(num);
	}
	cout<<sockMerchant(n, ar);
	return 0;
}