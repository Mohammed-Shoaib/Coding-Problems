// Problem Code: PALL01

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string blockGame(int N){
    string s1 = to_string(N);
    string s2(s1);
    reverse(s2.begin(), s2.end());
    return (s1 == s2) ? "wins" : "losses";
}

int main()
{
    int T, N;
    cin >> T;
    for(int i=1 ; i<=T ; i++){
        cin >> N;
        cout << blockGame(N) << endl;
    }
    return 0;
}