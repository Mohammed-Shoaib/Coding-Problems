/*
Problem Statement: https://www.hackerrank.com/challenges/circular-array-rotation/problem
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> circularArrayRotation(vector<int> a, int k, vector<int> queries) {
    vector<int> values;
    k %= a.size();
    rotate(a.begin(),a.end()-k,a.end());
    for(int query:queries)
        values.push_back(a[query]);
    return values;
}

int main()
{
    int n,k,q,m,num;
    vector<int> a,queries,values;
    cin>>n>>k>>q;
    for(int i=0 ; i<n ; i++){
        cin>>num;
        a.push_back(num);
    }
    for(int i=1 ; i<=q ; i++){
        cin>>m;
        queries.push_back(m);
    }
    values = circularArrayRotation(a,k,queries);
    for(int value:values)
        cout<<value<<endl;
    return 0;
}