// Problem Code: GCD2

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string gcd(int A, string B) {
    if(A == 0)
        return B;
    int len, rem;
    len = to_string(A).length() + 1;
    if(B.length() < len)
        return to_string(__gcd(A, stoi(B)));
    else {
        rem = stoi(string(B.begin(), B.begin() + len)) % A;
        B = to_string(rem) + string(B.begin() + len, B.end());
        return gcd(A, B);
    }
}

int main(){
    int T, A;
    string B;
    cin >> T;
    while(T--) {
        cin >> A >> B;
        cout << gcd(A, B) << endl;
    }
    return 0;
}