// Problem Code: PPSUM

#include <iostream>

using namespace std;

int puppyAndSum(int D, int N) {
    int sum = N;
    for(int i=1 ; i<=D ; i++)
        sum = sum*(sum+1)/2;
    return sum;
}

int main() {
    int T, D, N;
    cin >> T;
    while(T--) {
        cin >> D >> N;
        cout << puppyAndSum(D, N) << endl;
    }
    return 0;
}