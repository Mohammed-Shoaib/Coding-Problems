// Problem Code: DECSTR

#include <iostream>
#include <string>

using namespace std;

string decreasingString(int K){
    string s;
    K += (K-1)/25;
    for(int i=K ; i >= 0 ; i--)
        s += (i % 26) + 'a';
    return s;
}

int main(){
    int T, K;
    cin >> T;
    while(T--){
        cin >> K;
        cout << decreasingString(K) << endl;
    }
    return 0;
}