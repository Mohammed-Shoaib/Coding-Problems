/*
Problem Statement: https://www.hackerrank.com/challenges/sherlock-and-squares/problem
*/

#include <iostream>
#include <cmath>

using namespace std;

int squares(int a, int b) {
    return floor(sqrt(b)) - ceil(sqrt(a)) + 1;
}

int main()
{
    int q;
    cin>>q;
    for(int i=1 ; i<=q ; i++){
        int a,b;
        cin>>a>>b;
        cout<<squares(a,b)<<endl;
    }
    return 0;
}