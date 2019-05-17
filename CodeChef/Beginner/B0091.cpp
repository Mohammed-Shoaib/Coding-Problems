// Problem Code: CHCHCL

#include <iostream>

using namespace std;

string chefAndChocolate(int n, int m) {
    long prod = (long)n * m;
    return (prod & 1) ? "No" : "Yes"; 
}

int main(){
    int T, n, m;
    cin >> T;
    while(T--) {
        cin >> n >> m;
        cout << chefAndChocolate(n, m) << endl;
    }
    return 0;
}