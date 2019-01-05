// Problem Code: APPROX

#include <iostream>
#include <vector>

using namespace std;

void preprocess(vector<int> &q) {
    int d, rem;
    d = 33102;
    rem = 103993 % d;
    for (int i = 0 ; i < q.size() ; i++) {
        rem *= 10;
        q[i] = rem / d;
        rem %= d;
    }
}

int main() {
    int T, K;
    vector<int> q(1e6);
    preprocess(q);
    cin >> T;
    while (T--) {
        cin >> K;
        if (K == 0) {
            cout << 3 << endl;
            continue;
        }
        cout << 3 << '.';
        for (int i = 0 ; i < K ; i++)
            cout << q[i];
        cout << endl;
    }
    return 0;
}