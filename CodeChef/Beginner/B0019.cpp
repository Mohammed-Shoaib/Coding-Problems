// Problem Code: FLOW018

#include <iostream>

using namespace std;

int fact(int N, int prod){
    if(N <= 1)
        return prod;
    else
        return fact(N-1, N*prod);
}

int main()
{
    int T, N;
    cin >> T;
    for(int i=1 ; i<=T ; i++){
        cin >> N;
        cout << fact(N, 1) << endl;
    }
    return 0;
}