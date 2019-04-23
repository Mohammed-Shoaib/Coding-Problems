/*
Problem Statement: https://www.hackerrank.com/challenges/largest-permutation/problem
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> largestPermutation(int n, int k, vector<int> arr) {
    vector<int> sorted(arr);
    sort(sorted.rbegin(), sorted.rend());
    for (int j, i = 0; k > 0; k--, i++) {
        while (i < n && sorted[i] == arr[i])
            i++;
        if (i == n)
            break;
        j = distance(arr.begin(), find(arr.begin() + i, arr.end(), sorted[i]));
        swap(arr[i], arr[j]);
    }
    return arr;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n), permutation;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    permutation = largestPermutation(n, k, arr);
    for (int i = 0; i < n; i++)
        cout << permutation[i] << " ";
    cout << endl;
    return 0;
}