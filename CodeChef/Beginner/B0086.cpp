// Problem Code: SNAKPROC

#include <iostream>
#include <string>
#include <stack>

using namespace std;

string snakeProcession(string L) {
    stack<char> S;
    for(int i=0 ; i<L.length() ; i++) {
        if(L[i] == 'H') {
            if(S.size() == 1)
                return "Invalid";
            while(!S.empty())
                S.pop();
            S.push('H');
        } else if(L[i] == 'T') {
            if(S.size() == 0 || S.size() > 1)
                return "Invalid";
            S.push('T');
        }
    }
    return (S.empty() || S.size() == 2) ? "Valid" : "Invalid";
}

int main(){
    int R, L;
    string S;
    cin >> R;
    while(R--) {
        cin >> L >> S;
        cout << snakeProcession(S) << endl;
    }
    return 0;
}