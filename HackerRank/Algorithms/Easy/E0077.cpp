/*
Problem Statement: https://www.hackerrank.com/challenges/maximum-perimeter-triangle/problem
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> maximumPerimeterTriangle(vector<int> sticks) {
    sort(sticks.begin(), sticks.end());
    for (int i = sticks.size() - 1; i >= 2; i--)
        if (sticks[i - 2] + sticks[i - 1] > sticks[i])
            return {sticks[i - 2], sticks[i - 1], sticks[i]};
    return {-1};
}

int main() {
    int n;
    cin >> n;
    vector<int> sides, sticks(n);
    for (int i = 0; i < n; i++)
        cin >> sticks[i];
    sides = maximumPerimeterTriangle(sticks);
    for (int i = 0; i < sides.size(); i++)
        cout << sides[i] << " ";
    cout << endl;
}