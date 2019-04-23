// Problem Code: GDOG

#include <iostream>

using namespace std;

int greedyPuppy(int N, int K){
    int coins = 0;
    for(int j=K ; j>0 ; j--)
        if(coins < N % j)
            coins = N % j;
    return coins;
}

int main()
{
    int T, N, K;
    cin >> T;
    for(int i=1 ; i<=T ; i++){
        cin >> N >> K;
        cout << greedyPuppy(N, K) << endl;
    }
    return 0;
}