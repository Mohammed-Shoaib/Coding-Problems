/*
Problem Statement: https://www.hackerrank.com/challenges/alternating-characters/problem
*/

#include <iostream>
#include <string>

using namespace std;

int alternatingCharacters(string s) {
    int count = 0;
    char last = s[0];
    for(int i=1 ; i<s.length() ; last=s[i], i++)
        if(s[i] == last)
            count++;
    return count;
}

int main()
{
    int q;
    string s;
    cin>>q;
    cin.ignore();
    for(int i=1 ; i<=q ; i++){
        getline(cin, s);
        cout<<alternatingCharacters(s)<<endl;
    }
    return 0;
}