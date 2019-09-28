/*
Problem Statement: https://www.hackerrank.com/challenges/sherlock-and-array/problem
*/

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

string balancedSums(vector<int> &arr) {
    int n, sum, left, right;
    n = arr.size();
    sum = accumulate(arr.begin(), arr.end(), 0);
    left = 0;
    right = sum;

    for (int i = 0; i < n; i++) {
        right -= arr[i];
        if (left == right)
            return "YES";
        left += arr[i];
    }

    return "NO";
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        cout << balancedSums(arr) << endl;
    }
	return 0;
}