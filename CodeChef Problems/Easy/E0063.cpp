// Problem Code: RRECIPE

#include <iostream>
#include <string>

using namespace std;

int recipeReconstruction(string S) {
    int i, j, mod;
    long long ways = 1;
    i = 0;
    j = S.length() - 1;
    mod = 1e7 + 9;
    while (i <= j) {
        if (S[i] == '?' && S[j] == '?')
            ways = (ways * 26) % mod;
        else if (S[i] != '?' && S[j] != '?' && (S[i] != S[j]))
            return 0;
        i++;
        j--;
    }
    return ways;
}

int main() {
    int T;
    string S;
    cin >> T;
    while (T--) {
        cin >> S;
        cout << recipeReconstruction(S) << endl;
    }
    return 0;
}