/*
Problem Statement: https://www.hackerrank.com/challenges/bigger-is-greater/problem
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string biggerIsGreater(string w) {
    return (next_permutation(w.begin(), w.end())) ? w : "no answer";
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        string w;
        cin >> w;
        cout << biggerIsGreater(w) << endl;
    }
    return 0;
}