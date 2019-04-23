/*
Problem Statement: https://www.hackerrank.com/challenges/luck-balance/problem
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int luckBalance(int k, vector< vector<int> > contests) {
    int luck = 0;
    sort(contests.rbegin(), contests.rend());
    for (int i = 0; i < contests.size(); i++) {
        if (!contests[i][1])
            luck += contests[i][0];
        else {
            if (k != 0) {
                luck += contests[i][0];
                k--;
            }
            else
                luck -= contests[i][0];
        }
    }
    return luck;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector< vector<int> > contests(n, vector<int>(2));
    for (int i = 0; i < n; i++)
        cin >> contests[i][0] >> contests[i][1];
    cout << luckBalance(k, contests);
    return 0;
}