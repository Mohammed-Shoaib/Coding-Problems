/*
Problem Statement: https://www.hackerrank.com/challenges/tutorial-intro/problem
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int introTutorial(int V, vector<int> arr) {
    return distance(arr.begin(), find(arr.begin(), arr.end(), V));
}

int main() {
    int V, n;
    cin >> V >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << introTutorial(V, arr);
}