/*
Problem Statement: https://www.hackerrank.com/challenges/minimum-distances/problem
*/

#include <iostream>
#include <vector>
#include <map>
#include <climits>
#include <iterator>

using namespace std;

int minimumDistances(vector<int> a) {
    map<int, int> indices;
    int minDist = INT_MAX;
    for(int i=0 ; i<a.size() ; i++){
        if(minDist == 1)
            break;
        map<int, int>::iterator it = indices.find(a[i]);
        if(it != indices.end()){
            int dist = i - it->second;
            if(dist < minDist)
                minDist = dist;
            it->second = i;
        }
        else
            indices[a[i]] = i;
    }
    return (minDist == INT_MAX) ? -1 : minDist;
}

int main()
{
    int n, num;
    vector<int> a;
    cin>>n;
    for(int i=0 ; i<n ; i++){
        cin>>num;
        a.push_back(num);
    }
    cout<<minimumDistances(a);
    return 0;
}