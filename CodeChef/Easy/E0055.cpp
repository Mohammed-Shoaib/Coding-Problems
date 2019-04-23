// Problem Code: ABGAME

#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <functional>

using namespace std;

char winner(string S) {
    int a, b, count, XOR;
    vector<int> nims;
    a = b = 0;
    for(int j, i=0 ; i<S.length() ; i++)
        if(S[i] != '.') {
            count = 0;
            for(j = i+1 ; j < S.length() && S[j] == '.' ; j++)
                count++;
            if(j != S.length() && S[i] != S[j])
                nims.push_back(count);
            else {
                if(S[i] == 'A')
                    a += count;
                else
                    b += count;
            }
            i = j;
        }
    if(a != b)
        return (a > b) ? 'A' : 'B';
    XOR = accumulate(nims.begin(), nims.end(), 0, bit_xor<int>());
    return (XOR) ? 'A' : 'B';
}

int main() {
    int T;
    string s;
    cin >> T;
    while(T--) {
        cin >> s;
        cout << winner(s) << endl;
    }
    return 0;
}