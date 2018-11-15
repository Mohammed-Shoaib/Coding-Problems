// Problem Code: TWOSTR

#include <iostream>
#include <string>

using namespace std;

string chefAndWildcard(string X, string Y) {
    for(int i=0 ; i<X.length() ; i++)
        if( (X[i] != Y[i]) && (X[i] != '?' && Y[i] != '?') )
            return "No";
    return "Yes";
}

int main() {
    int T;
    string X, Y;
    cin >> T;
    while(T--) {
        cin >> X >> Y;
        cout << chefAndWildcard(X, Y) << endl;
    }
    return 0;
}