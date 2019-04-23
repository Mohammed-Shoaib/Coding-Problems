// Problem Code: ANUDTC

#include <iostream>
#include <string>

using namespace std;

string divideTheCake(int N){
    string s = "n n n";
    if(360 % N == 0)
        s[0] = 'y';
    if(N <= 360)
        s[2] = 'y';
    if(N*(N+1)/2 <= 360)
        s[4] = 'y';
    return s;
}

int main(){
    int T, N;
    cin >> T;
    while(T--){
        cin >> N;
        cout << divideTheCake(N) << endl;
    }
    return 0;
}