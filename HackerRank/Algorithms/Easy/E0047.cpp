/*
Problem Statement: https://www.hackerrank.com/challenges/electronics-shop/problem
*/

#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

int getMoneySpent(vector<int> keyboards, vector<int> drives, int b) {
	int max = -1;
	sort(keyboards.begin(), keyboards.end(), greater<int>());
	sort(drives.begin(), drives.end());
	for(int i=0 ; i<keyboards.size() ; i++)
		for(int j=0 ; j<drives.size() ; j++){
			int sum = keyboards[i] + drives[j];
			if(sum > b)
				break;
			else if(sum > max)
				max = sum;
		}
	return max;
}

int main()
{
	int b, n, m, num;
	vector<int> keyboards, drives;
	cin>>b>>n>>m;
	for(int i=0 ; i<n ; i++){
		cin>>num;
		keyboards.push_back(num);
	}
	for(int i=0 ; i<m ; i++){
		cin>>num;
		drives.push_back(num);
	}
	cout<<getMoneySpent(keyboards, drives, b);
	return 0;
}