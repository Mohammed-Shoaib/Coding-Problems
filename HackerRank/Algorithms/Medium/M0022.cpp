/*
Problem Statement: https://www.hackerrank.com/challenges/richie-rich/problem
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string highestValuePalindrome(string &s, int n, int k) {
    int i, j;
    vector<bool> changed(n);

    for (i = 0, j = n - 1; i < n / 2; i++, j--)
        if (s[i] != s[j]) {
            if (k == 0)
                return "-1";
            s[i] = s[j] = max(s[i], s[j]);
            changed[i] = changed[j] = true;
            k--;
        }
    
    for (i = 0, j = n - 1; i <= n / 2 && k != 0; i++, j--) {
        if (s[i] == '9' && s[j] == '9')
            continue;
        else if (changed[i] || i == j) {
            s[i] = s[j] = '9';
            k--;
        } else if (k > 1) {
            s[i] = s[j] = '9';
            k -= 2;
        }
    }

    return s;
}

int main() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    cout << highestValuePalindrome(s, n, k);
    return 0;
}