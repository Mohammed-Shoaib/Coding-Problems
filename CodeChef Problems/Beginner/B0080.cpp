// Problem Code: TICKETS5

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string tickets(string S) {
    if(S[0] == S[1])
        return "NO";
    for(int i=0 ; i<S.length()-2 ; i++)
        if(S[i] != S[i+2])
            return "NO";
    return "YES";
}

int main() {
    int T;
    string S;
    cin >> T;
    while(T--) {
        cin >> S;
        cout << tickets(S) << endl;
    }
    return 0;
}