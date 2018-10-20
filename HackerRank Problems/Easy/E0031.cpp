/*
Problem Statement: https://www.hackerrank.com/challenges/find-digits/problem
*/

#include <iostream>
#include <string>

using namespace std;

int findDigits(int n) {
    int count = 0;
    string s = to_string(n);
    for(char c:s){
        int d = c - '0';
        if(d && !(n%d))
            count++;
    }
    return count;
}

int main()
{
    int t;
    cin>>t;
    for(int i=1 ; i<=t ; i++){
        int n;
        cin>>n;
        cout<<findDigits(n)<<endl;
    }
    return 0;
}
