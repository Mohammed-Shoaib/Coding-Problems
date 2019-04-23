/*
Problem Statement: https://www.hackerrank.com/challenges/beautiful-triplets/problem
*/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int beautifulTriplets(int d, vector<int> arr) {
    int count = 0;
    unordered_set<int> hashSet;
    for(int i=0 ; i<arr.size() ; i++){
        bool isBeautifulTriplet = (hashSet.find(arr[i]-d) != hashSet.end()) && (hashSet.find(arr[i]-2*d) != hashSet.end());
        if(isBeautifulTriplet)
            count++;
        hashSet.insert(arr[i]);
    }
    return count;
}

int main()
{
    int n, d, num;
    vector<int> arr;
    cin>>n>>d;
    for(int i=0 ; i<n ; i++){
        cin>>num;
        arr.push_back(num);
    }
    cout<<beautifulTriplets(d, arr);
    return 0;
}