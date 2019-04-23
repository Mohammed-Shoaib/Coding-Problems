// Problem Code: FLOW008

#include <iostream>

using namespace std;

string servant(int N){
    string s = "What an obedient servant you are!";
    return (N < 10) ? s : "-1";
}

int main()
{
    int T, N;
    cin >> T;
    for(int i=1 ; i<=T ; i++){
        cin >> N;
        cout << servant(N) << endl;
    }
    return 0;
}