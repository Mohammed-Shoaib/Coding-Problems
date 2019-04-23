// Problem Code: DISCHAR

#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int distinctCharactersSubsequence(string S) {
    return unordered_set<char> (S.begin(), S.end()).size();
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        string S;
        cin >> S;
        cout << distinctCharactersSubsequence(S) << endl;
    }
    return 0;
}