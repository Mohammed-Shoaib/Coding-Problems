/*
Problem Statement: https://www.hackerrank.com/challenges/caesar-cipher-1/problem
*/

#include <iostream>
#include <string>

using namespace std;

string caesarCipher(string s, int k) {
    for(int i=0 ; i<s.length() ; i++){
        if(!isalpha(s[i]))
            continue;
        if(isupper(s[i])){
            s[i] -= 65;
            s[i] = (s[i]+k)%26;
            s[i] += 65;
        }else{
            s[i] -= 97;
            s[i] = (s[i]+k)%26;
            s[i] += 97;
        }
    }
    return s;
}

int main()
{
    int n, k;
    string s;
    cin>>n;
    cin.ignore();
    getline(cin, s);
    cin>>k;
    cout<<caesarCipher(s, k);
    return 0;
}