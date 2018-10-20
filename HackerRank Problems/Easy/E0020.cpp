/*
Problem Statement: https://www.hackerrank.com/challenges/angry-professor/problem
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string angryProfessor(int k, vector<int> a) {
    a.erase(remove_if(a.begin(),a.end(),bind2nd(greater<int>(),0)),a.end());
    return ((int)a.size()-k<0) ? "YES" : "NO";
}

int main()
{
    int t;
    cin>>t;
    for(int i=1 ; i<=t ; i++){
        int n,k,num;
        vector<int> a;
        cin>>n>>k;
        for(int i=0 ; i<n ; i++){
            cin>>num;
            a.push_back(num);
        }
        cout<<angryProfessor(k,a)<<endl;
    }
    return 0;
}