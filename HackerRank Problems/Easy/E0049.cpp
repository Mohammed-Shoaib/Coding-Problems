/*
Problem Statement: https://www.hackerrank.com/challenges/funny-string/problem
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

string funnyString(string s) {
    vector<int> arr, arr2;
    string s2(s);
    reverse(s2.begin(), s2.end());
    for(int i=0 ; i<s.length()-1 ; i++){
        arr.push_back(abs(s[i] - s[i+1]));
        arr2.push_back(abs(s2[i] - s2[i+1]));
    }
    return (arr == arr2) ? "Funny" : "Not Funny";
}

int main()
{
    int q;
    string s;
    cin>>q;
    cin.ignore();
    for(int i=1 ; i<=q ; i++){
        getline(cin, s);
        cout<<funnyString(s)<<endl;
    }
    return 0;
}