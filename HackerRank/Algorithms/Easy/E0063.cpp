/*
Problem Statement: https://www.hackerrank.com/challenges/closest-numbers/problem
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> closestNumbers(vector<int> arr) {
    int min, pos;
    vector<int> results;
    sort(arr.begin(), arr.end());
    pos = 0;
    min = arr[1] - arr[0];
    for(int i=1 ; i<arr.size()-1 ; i++)
        if(arr[i+1] - arr[i] < min){
            pos = i;
            min = arr[i+1] - arr[i];
        }
    for(int i=pos ; i<arr.size()-1 ; i++)
        if(arr[i+1] - arr[i] == min){
            results.push_back(arr[i]);
            results.push_back(arr[i+1]);
        }
    return results;
}

int main()
{
    int n, num;
    vector<int> arr, pairs;
    cin>>n;
    for(int i=0 ; i<n ; i++){
        cin>>num;
        arr.push_back(num);
    }
    pairs = closestNumbers(arr);
    for(int i=0 ; i<pairs.size() ; i++)
        cout<<pairs[i]<<" ";
    cout<<endl;
    return 0;
}