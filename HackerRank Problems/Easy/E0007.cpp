/*
Problem Statement: https://www.hackerrank.com/challenges/staircase/problem
*/

#include <iostream>

using namespace std;

void staircase(int n) {
    for(int i=0 ; i<n ; i++){
        for(int j=n-i-1 ; j>0 ; j--)
            cout<<" ";
        for(int j=0 ; j<=i ; j++)
            cout<<"#";
        cout<<endl;
    }
}

int main()
{
    int n;
    cin >> n;
    staircase(n);
    return 0;
}
