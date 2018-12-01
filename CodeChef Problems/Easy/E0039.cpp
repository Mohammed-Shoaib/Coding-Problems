// Problem Code: DRAGNXOR

#include <iostream>
#include <bitset>
#include <cmath>
#define M 30

using namespace std;

int openTheDragonScroll(int N, int A, int B){
    int num, ones, A0, A1, B0, B1;
    bitset<M> b1(A), b2(B);
    num = 0;
    A1 = b1.count();
    A0 = N - A1;
    B1 = b2.count();
    B0 = N - B1;
    ones = min(A1, B0) + min(B1, A0);
    for(int i = N-1 ; i >= N-ones ; i--)
        num += pow(2, i);
    return num;
}

int main(){
    int T, N, A, B;
    cin >> T;
    while(T--){
        cin >> N >> A >> B;
        cout << openTheDragonScroll(N, A, B) << endl;
    }
    return 0;
}