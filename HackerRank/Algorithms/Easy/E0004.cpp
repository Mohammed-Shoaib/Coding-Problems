/*
Problem Statement: https://www.hackerrank.com/challenges/a-very-big-sum/problem
*/

#include <iostream>
#include <vector>

using namespace std;

long aVeryBigSum(vector<long> arr) {
	long sum = 0;
	for(int num: arr)
		sum += num;
	return sum;
}

int main()
{
	int len, num;
	cin>>len;
	vector<long> arr;
	for(int i=0 ; i<len ; i++){
		cin>>num;
		arr.push_back(num);
	}
	cout<<aVeryBigSum(arr);
	return 0;
}