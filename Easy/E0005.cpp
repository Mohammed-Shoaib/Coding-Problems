/*
Problem Statement: https://www.hackerrank.com/challenges/diagonal-difference/problem
*/

#include <iostream>
#include <vector>

using namespace std;

int diagonalDifference(vector<vector<int>> arr) {
    int left,right;
    left = right = 0;
    for(int i=0,j=arr[i].size()-1 ; i<arr.size() ; i++,j--){
        left += arr[i][i];
        right += arr[i][j];
    }
    return abs(left-right);
}

int main()
{
    int len,num;
    cin>>len;
    vector<vector<int>> arr;
    for(int i=0 ; i<len ; i++){
        arr.push_back(vector<int>());
        for(int j=0 ; j<len ; j++){
            cin>>num;
            arr[i].push_back(num);
        }
    }
    cout<<diagonalDifference(arr);
    return 0;
}