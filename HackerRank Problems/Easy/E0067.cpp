/*
Problem Statement: https://www.hackerrank.com/challenges/icecream-parlor/problem
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
#include <algorithm>

using namespace std;

pair<int, int> icecreamParlor(int m, vector<int> arr) {
    unordered_map<int, int> map;
    pair<int, int> result;
    for(int i=0 ; i<arr.size() ; i++){
        if(map.find(arr[i]) != map.end()){
            result = make_pair(map[arr[i]], i+1);
            break;
        }
        map[m - arr[i]] = i+1;
    }
    return result;
}

int main()
{
    int t, m, n, num;
    vector<int> cost;
    pair<int, int> result;
    cin>>t;
    for(int i=1 ; i<=t ; i++){
        cin>>m>>n;
        for(int i=0 ; i<n ; i++){
            cin>>num;
            cost.push_back(num);
        }
        result = icecreamParlor(m, cost);
        cout<<result.first<<" "<<result.second<<endl;
        cost.clear();
    }
    return 0;
}