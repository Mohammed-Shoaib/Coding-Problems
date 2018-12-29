// Problem Code: RRSTONE

#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

void stone(int K, vector<long long> &A) {
    if (K == 0)
        return;
    K = (K & 1) ? 1 : 2;
    while (K--) {
        long long max = *max_element(A.begin(), A.end());
        transform(A.begin(), A.end(), A.begin(), bind1st(minus<long long>(), max));
    }
    return;
}

int main() {
    int N, K, num;
    cin >> N >> K;
    vector<long long> A(N);
    for (int i = 0 ; i < N ; i++)
        cin >> A[i];
    stone(K, A);
    for (int i = 0 ; i < N ; i++)
        cout << A[i] << " ";
    cout << endl;
    return 0;
}