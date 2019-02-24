/*
Problem Statement: https://www.hackerrank.com/challenges/grid-challenge/problem
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string gridChallenge(vector<string> grid) {
    for (int i = 0; i < grid.size(); i++)
        sort(grid[i].begin(), grid[i].end());
    for (int i = 0; i < grid.size(); i++)
        for (int j = 1; j < grid.size(); j++)
            if (grid[j - 1][i] > grid[j][i])
                return "NO";
    return "YES";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<string> grid(n);
        for (int i = 0; i < n; i++)
            cin >> grid[i];
        cout << gridChallenge(grid) << endl;
    }
    return 0;
}