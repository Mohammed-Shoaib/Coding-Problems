// Problem Code: TWONMS

#include <iostream>
#include <cmath>

using namespace std;

int twoNumbers(int A, int B, int N) {
    if(N & 1)
        A *= 2;
    return max(A, B) / min(A, B);
}

int main() {
    int T, A, B, N;
    cin >> T;
    while(T--) {
        cin >> A >> B >> N;
        cout << twoNumbers(A, B, N) << endl;
    }
    return 0;
}