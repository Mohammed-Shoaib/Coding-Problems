/*
Problem Statement: https://www.hackerrank.com/challenges/birthday-cake-candles/problem
*/

#include <iostream>
#include<vector>

using namespace std;

int birthdayCakeCandles(vector<int> arr) {
	int count = 1;
	int max = arr[0];
	for(int i=1 ; i<arr.size() ; i++){
		if(max == arr[i])
			count++;
		else if(max < arr[i]){
			max = arr[i];
			count = 1;
		}
	}
	return count;
}

int main()
{
	int len,num;
	vector<int> arr;
	cin>>len;
	for(int i=0 ; i<len ; i++){
		cin>>num;
		arr.push_back(num);
	}
	cout<<birthdayCakeCandles(arr)<<endl;
	return 0;
}