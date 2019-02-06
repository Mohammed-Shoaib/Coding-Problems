/*
Problem Statement: https://www.hackerrank.com/challenges/separate-the-numbers/problem
*/

#include <iostream>
#include <string>

using namespace std;

string separateNumbers(string s) {
    long long n;
    string x, t;
    for (int i = 1; i <= s.length() / 2; i++) {
        x = t = s.substr(0, i);
        n = stoll(x);
        for (int j = 1; t.size() < s.size(); j++)
            t += to_string(n + j);
        if (s == t)
            return "YES " + x;
    }
    return "NO";
}

int main() {
    int q;
    cin >> q;
    while (q--) {
        string s;
        cin >> s;
        cout << separateNumbers(s) << endl;
    }
}