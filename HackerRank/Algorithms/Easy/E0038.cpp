/*
Problem Statement: https://www.hackerrank.com/challenges/pangrams/problem
*/

#include <iostream>
#include <string>
#include <set>

using namespace std;

string pangrams(string s) {
    set<char> alphabets;
    for(int i=0 ; i < s.length() ; i++){
        char c = tolower(s.at(i));
        if(c == ' ')
            continue;
        alphabets.insert(c);
        if(alphabets.size() == 26)
            return "pangram";
    }
    return "not pangram";
}

int main()
{
    string s;
    getline(cin, s);
    cout<<pangrams(s);
    return 0;
}
