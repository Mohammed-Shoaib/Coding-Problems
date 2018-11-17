// Problem Code: ALTARAY

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long devuAndGrapes(int K, vector<int> N) {
    int R;
    long grapes;
    grapes = 0;
    for(int i=0 ; i<N.size() ; i++) {
        R = N[i] % K;
        if(N[i] < K)
            grapes += K - R;
        else
            grapes += min(R, K-R);
    }
    return grapes;
}

int main() {
    int T, N, K, num;
    vector<int> A;
    cin >> T;
    while(T--) {
        cin >> N >> K;
        for(int i=0 ; i<N ; i++) {
            cin >> num;
            A.push_back(num);
        }
        cout << devuAndGrapes(K, A) << endl;
        A.clear();
    }
    return 0;
}