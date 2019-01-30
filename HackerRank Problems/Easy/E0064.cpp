/*
Problem Statement: https://www.hackerrank.com/challenges/find-the-median/problem
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int partition(vector<int> &arr, int low, int high){
    int pivot = arr[high];
    int i = low-1;
    for(int j=low ; j<high ; j++)
        if(arr[j] < pivot){
            i++;
            iter_swap(&arr[i], &arr[j]);
        }
    i++;
    iter_swap(&arr[i], &arr[high]);
    return i;
}

int quickSelect(vector<int> &arr, int left, int right, int k){
    if(left == right)
        return arr[left];
    int split = partition(arr, left, right);
    if(split == k)
        return arr[split];
    else if(k < split)
        return quickSelect(arr, left, split-1, k);
    else
        return quickSelect(arr, split+1, right, k);
}

int findMedian(vector<int> arr) {
    return quickSelect(arr, 0, arr.size()-1, arr.size()/2);
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
    cout<<findMedian(arr);
    return 0;
}