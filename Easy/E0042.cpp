/*
Problem Statement: https://www.hackerrank.com/challenges/flatland-space-stations/problem
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int flatlandSpaceStations(int n, vector<int> c) {
    vector<int> lengths;
    sort(c.begin(), c.end());
    lengths.push_back(c[0]);
    for(int i=1 ; i<c.size() ; i++)
        lengths.push_back(c[i]- c[i-1] - 1);
    lengths.push_back(n-c[c.size()-1] - 1);
    int max = (*max_element(lengths.begin()+1, lengths.end()) + 1)/2;
    int special = (lengths[0] > lengths[lengths.size()-1]) ? lengths[0] : lengths[lengths.size()-1];
    return (max > special) ? max : special;
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
    cout<<flatlandSpaceStations(n, c);
    return 0;
}