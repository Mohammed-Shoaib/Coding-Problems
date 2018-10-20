/*
Problem Statement: https://www.hackerrank.com/challenges/migratory-birds/problem
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int migratoryBirds(vector<int> arr) {
    int maxFreq, freq, num;
    num = arr[0];
    maxFreq = freq = 1;
    sort(arr.begin(), arr.end());
    for(int i=0 ; i<arr.size()-1 ; i++){
        if(arr[i] == arr[i+1])
            freq++;
        else
            freq = 1;
        if(freq > maxFreq){
            maxFreq = freq;
            num = arr[i];
        }
    }
    return num;
}

int main()
{
    int n, num;
    vector<int> arr;
    cin>>n;
    for(int i=0 ; i<n ; i++){
        cin>>num;
        arr.push_back(num);
    }
    cout<<migratoryBirds(arr);
    return 0;
}