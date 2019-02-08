/*
Problem Statement: https://www.hackerrank.com/challenges/minimum-absolute-difference-in-an-array/problem
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int minimumAbsoluteDifference(vector<int> arr) {
    int min = numeric_limits<int>::max();
    sort(arr.begin(), arr.end());
    for (int i = 1; i < arr.size(); i++)
        if (arr[i] - arr[i - 1] < min)
            min = arr[i] - arr[i - 1];
    return min;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << minimumAbsoluteDifference(arr);
    return 0;
}