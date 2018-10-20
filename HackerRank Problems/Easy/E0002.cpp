/*
Problem Statement: https://www.hackerrank.com/challenges/simple-array-sum/problem
*/

#include <iostream>
#include <vector>

using namespace std;

int simpleArraySum(vector<int> arr) {
    int sum = 0;
    for(int i=0 ; i<arr.size() ; i++)
        sum += arr[i];
    return sum;
}

int main()
{
    int len, num;
    cin>>len;
    vector<int> arr;
    for(int i=0 ; i<len ; i++){
        cin>>num;
        arr.push_back(num);
    }
    cout<<simpleArraySum(arr);
    return 0;
}
