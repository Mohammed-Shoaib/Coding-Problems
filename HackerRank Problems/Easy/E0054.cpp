/*
Problem Statement: https://www.hackerrank.com/challenges/making-anagrams/problem
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int makingAnagrams(string s1, string s2) {
    size_t pos;
    int count = 0;
    for(int i=s1.length()-1 ; i>=0 ; i--){
        pos = s2.find(s1[i]);
        if(pos == string::npos)
            count++;
        else
            s2.erase(pos, 1);
        s1.erase(i, 1);
    }
    for(int i=s2.length()-1 ; i>=0 ; i--){
        pos = s1.find(s2[i]);
        if(pos == string::npos)
            count++;
        else
            s1.erase(pos, 1);
        s2.erase(i, 1);
    }
    return count;
}

int main()
{
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    cout<<makingAnagrams(s1, s2);
    return 0;
}