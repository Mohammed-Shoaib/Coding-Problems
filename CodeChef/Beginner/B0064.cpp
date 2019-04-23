// Problem Code: ALPHABET

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string studyingAlphabet(string W, vector<bool> letters) {
    for(char &c : W)
        if(!letters[c-'a'])
            return "No";
    return "Yes";
}

int main() {
    int N;
    string S, W;
    vector<bool> letters(26);
    cin >> S >> N;
    for(char &c : S)
        letters[c-'a'] = true;
    while(N--) {
        cin >> W;
        cout << studyingAlphabet(W, letters) << endl;
    }
    return 0;
}