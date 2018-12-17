// Problem Code: BEAUTGAR

#include <iostream>
#include <string>

using namespace std;

string beautifulGarland(string s) {
    int reds, greens;
    reds = greens = 0;
    if(s.length() & 1)
        return "no";
    else if(s[s.length()-1] == s[0])
        (s[0] == 'R') ? reds++ : greens++;
    for(int i=0 ; i<s.length()-1 ; i++) {
        if(s[i] == s[i+1])
            (s[i] == 'R') ? reds++ : greens++;
        if(reds > 1 || greens > 1)
            return "no";
    }
    return "yes";
}

int main() {
    int T;
    string s;
    cin >> T;
    while(T--) {
        cin >> s;
        cout << beautifulGarland(s) << endl;
    }
    return 0;
}