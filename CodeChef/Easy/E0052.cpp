// Problem Code: CSUB

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

long countSubstrings(string S) {
    long ones = count(S.begin(), S.end(), '1');
    return ones*(ones+1)/2;
}

int main(){
    int T, N;
    string S;
    cin >> T;
    while(T--) {
        cin >> N >> S;
        cout << countSubstrings(S) << endl;
    }
    return 0;
}