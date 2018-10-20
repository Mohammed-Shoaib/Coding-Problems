/*
Problem Statement: https://www.hackerrank.com/challenges/permutation-equation/problem
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> permutationEquation(vector<int> p) {
    vector<int> results, indices(p.size()+1);
    for(int i=0 ; i<p.size() ; i++)
        indices[p[i]] = i+1;
    for(int i=1 ; i<=p.size() ; i++)
        results.push_back(indices[indices[i]]);
    return results;
}

int main()
{
    int n, num;
    vector<int> p, results;
    cin>>n;
    for(int i=0 ; i<n ; i++){
        cin>>num;
        p.push_back(num);
    }
    results = permutationEquation(p);
    for(int i=0 ; i<results.size() ; i++)
        cout<<results[i]<<endl;
    return 0;
}