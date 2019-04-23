// Problem Code: CHEFSTLT

#include <iostream>
#include <string>

using namespace std;

void chefAndTwoStrings(string S1, string S2) {
    int min, max;
    min = max = 0;
    for(int i=0 ; i<S1.length() ; i++) {
        if(S1[i] == '?' || S2[i] == '?')
            max++;
        else if(S1[i] != S2[i]) {
            min++;
            max++;
        }
    }
    cout << min << " " << max << endl;
}

int main() {
    int T;
    string S1, S2;
    cin >> T;
    while(T--) {
        cin >> S1 >> S2;
        chefAndTwoStrings(S1, S2);
    }
    return 0;
}