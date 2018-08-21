/*
Problem Statement: https://www.hackerrank.com/challenges/mini-max-sum/problem
*/

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

void miniMaxSum(vector<int> arr) {
    int min,max;
    min = max = arr[0];
    for(int i=0 ; i<arr.size() ; i++){
        if(min > arr[i])
            min = arr[i];
        else if(max < arr[i])
            max = arr[i];
    }
    long long minSum = accumulate(arr.begin(), arr.end(), (long long)0) - max;
    long long maxSum = accumulate(arr.begin(), arr.end(), (long long)0) - min;
    printf("%lld %lld\n",minSum,maxSum);
}

int main()
{
    int num,len=5;
    vector<int> arr;
    for(int i=0 ; i<len ; i++){
        cin>>num;
        arr.push_back(num);
    }
    miniMaxSum(arr);
    return 0;
}