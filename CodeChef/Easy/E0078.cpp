// Problem Code: BROKPHON

#include <iostream>
#include <vector>

using namespace std;

int brokenTelephone(vector<int> A) {
    int count = 0;
    bool samePerson = false;
    for (int i=1 ; i < A.size() ; i++) {
        if (A[i] != A[i-1]) {
            if (!samePerson)
                count++;
            count++;
            samePerson = true;
        }
        else
            samePerson = false;
    }
    return count;
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
        cout << brokenTelephone(A) << endl;
    }
    return 0;
}