/*
Problem Statement: https://www.hackerrank.com/challenges/save-the-prisoner/problem
*/

#include <iostream>

using namespace std;

int saveThePrisoner(int n, int m, int s) {
    return (s+m-2)%n+1;
}

int main()
{
    int t;
    cin>>t;
    for(int i=1 ; i<=t ; i++){
        int n,m,s;
        cin>>n>>m>>s;
        cout<<saveThePrisoner(n,m,s)<<endl;
    }
    return 0;
}