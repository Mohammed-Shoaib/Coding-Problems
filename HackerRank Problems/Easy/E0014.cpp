/*
Problem Statement: https://www.hackerrank.com/challenges/drawing-book/problem
*/

#include <iostream>
#include <cmath>

using namespace std;

int pageCount(int n, int p) {
    return (floor(n/2) >= p) ? floor(p/2) : floor(n/2) - floor(p/2);
}

int main()
{
    int n,p;
    cin>>n>>p;
    cout<<pageCount(n,p);
    return 0;
}
