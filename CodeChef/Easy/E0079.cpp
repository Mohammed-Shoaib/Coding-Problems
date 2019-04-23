// Problem Code: LEDIV

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int size = pow(10, 5);
vector<int> leastPrime(size + 1, 0);

void modifiedSieveOfEratosthenes() {
    int i, j;
    leastPrime[1] = 1;
    for (i = 2; i * i <= size; i++)
        if (leastPrime[i] == 0) {
            leastPrime[i] = i;
            for (j = 2 * i; j <= size; j += i)
                if (leastPrime[j] == 0)
                    leastPrime[j] = i;
        }
    for (; i <= size; i++)
        if (leastPrime[i] == 0)
            leastPrime[i] = i;
}

int littleElephantAndDivisors(vector<int> A) {
    int x, gcd = A[0];
    for (int i=1 ; i < A.size() ; i++)
            gcd = __gcd(A[i], gcd);
    return leastPrime[gcd];
}

int main() {
    modifiedSieveOfEratosthenes();
    leastPrime[1] = -1;
    int T;
    cin >> T;
    while (T--) {
            int N;
            cin >> N;
            vector<int> A(N);
            for (int i=0 ; i < N ; i++)
                    cin >> A[i];
            cout << littleElephantAndDivisors(A) << endl;
    }
    return 0;
}