// Problem Code: RECTANGL

#include <iostream>

using namespace std;

string rectangle(int a, int b, int c, int d) {
    return (a^b^c^d) ? "NO" : "YES";
}

int main() {
    int T, a, b, c, d;
    cin >> T;
    while(T--) {
        cin >> a >> b >> c >> d;
        cout << rectangle(a, b, c, d) << endl;
    }
    return 0;
}