// Problem Code: PROSUM

#include <iostream>
#include <vector>

using namespace std;

long long NC2(long long n) {
    return n * (n - 1) / 2;
}

long long littleChefAndNumbers(vector<int> A) {
    long long count, count_2;
    count = count_2 = 0;
    for (int i=0 ; i < A.size() ; i++) {
        if (A[i] == 2)
            count_2++;
        else if (A[i] > 2)
            count++;
    }
    return NC2(count) + count * count_2;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i=0 ; i < N ; i++)
            cin >> A[i];
        cout << littleChefAndNumbers(A) << endl;
    }
    return 0;
}