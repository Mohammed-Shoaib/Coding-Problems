/*
Problem Statement: https://www.hackerrank.com/challenges/mark-and-toys/problem
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maximumToys(vector<int> prices, int k) {
    int toys = 0;
    sort(prices.begin(), prices.end());
    for (int i = 0; i < prices.size() && k >= prices[i]; i++) {
        k -= prices[i];
        toys++;
    }
    return toys;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> prices(n);
    for (int i = 0; i < n; i++)
        cin >> prices[i];
    cout << maximumToys(prices, k);
    return 0;
}