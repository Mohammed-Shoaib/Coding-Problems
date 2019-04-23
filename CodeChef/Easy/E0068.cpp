// Problem Code: AMMEAT

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minimumPlates(long long M, vector<long long> P) {
    int i;
    long long sum = 0;
    sort (P.rbegin(), P.rend());
    for (i = 0 ; i < P.size() ; i++) {
        sum += P[i];
        if (sum >= M)
            break;
    }
    return (i == P.size()) ? -1 : (i + 1);
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        long long M;
        cin >> N >> M;
        vector<long long> P(N);
        for (int i = 0 ; i < N ; i++)
            cin >> P[i];
        cout << minimumPlates(M, P) << endl;
    }
    return 0;
}