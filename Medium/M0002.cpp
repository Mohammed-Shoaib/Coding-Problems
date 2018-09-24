/*
Problem Statement: https://www.hackerrank.com/challenges/coin-change/problem
*/

#include <iostream>
#include <vector>

using namespace std;

long getWays(int n, vector<int> c) {
    vector<long> numOfWays(n+1);
    numOfWays[0] = 1;
    for(int i=0 ; i<c.size() ; i++){
        for(int j=c[i] ; j<numOfWays.size() ; j++)
            numOfWays[j] += numOfWays[j - c[i]];
    }
    return numOfWays[n];
}

int main()
{
    int n, m, num;
    vector<int> c;
    cin>>n>>m;
    for(int i=0 ; i<m ; i++){
        cin>>num;
        c.push_back(num);
    }
    cout<<getWays(n, c);
    return 0;
}