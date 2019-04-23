/*
Problem Statement: https://www.hackerrank.com/challenges/beautiful-days-at-the-movies/problem
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int beautifulDays(int i, int j, int k) {
    int count = 0;
    for(int m=i ; m<=j ; m++){
        string temp(to_string(m));
        reverse(temp.begin(),temp.end());
        int n = stoi(temp);
        if((m-n)%k == 0)
            count++;
    }
    return count;
}

int main()
{
    int i,j,k;
    cin>>i>>j>>k;
    cout<<beautifulDays(i,j,k);
    return 0;
}