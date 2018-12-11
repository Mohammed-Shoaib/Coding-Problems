// Problem Code: ATTIC

#include <iostream>
#include <string>

using namespace std;

int atticCrossing(string P) {
    int days, jump, length;
    days = jump = 0;
    for(int i=0 ; i<P.length() ; i++)
        if(P[i] == '.') {
            length = 0;
            for(; i<P.length() && P[i] == '.' ; i++)
                length++;
            if(length > jump) {
                jump = length;
                days++;
            }
        }
    return days;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    string P;
    cin >> T;
    while(T--) {
        cin >> P;
        cout << atticCrossing(P) << endl;
    }
    return 0;
}