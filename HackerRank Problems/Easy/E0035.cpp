/*
Problem Statement: https://www.hackerrank.com/challenges/service-lane/problem
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> serviceLane(vector<int> width, vector<vector<int>> cases) {
    vector<int> results;
    for(int m=0 ; m<cases.size() ; m++){
        int min = *min_element(width.begin()+cases[m][0], width.begin()+cases[m][1]+1);
        results.push_back(min);
    }
    return results;
}

int main()
{
    int n, t, i, j, num;
    vector<int> width;
    vector<vector<int>> cases;
    cin>>n>>t;
    for(int k=0 ; k<n ; k++){
        cin>>num;
        width.push_back(num);
    }
    for(int k=1 ; k<=t ; k++){
        cin>>i>>j;
        cases.push_back(vector<int>{i,j});
    }
    vector<int> results = serviceLane(width, cases);
    for(int i=0 ; i<results.size() ; i++)
        cout<<results[i]<<endl;
    return 0;
}