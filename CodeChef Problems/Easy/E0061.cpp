// Problem Code: BPS

#include <iostream>
#include <utility>
#include <vector>
#include <numeric>
#include <functional>
#include <algorithm>

using namespace std;

string beatsAndPieces(vector<int> A, vector<int> l, vector<int> r) {
    int P, Q, L, R, gcd;
    vector<int> cpy, B(A), perm(l.size());
    P = Q = 0;
    iota(perm.begin(), perm.end(), 0);
    transform(l.begin(), l.end(), l.begin(), bind2nd(minus<int>(), 1));
    transform(r.begin(), r.end(), r.begin(), bind2nd(minus<int>(), 1));
    for(int i=0 ; i<perm.size() ; i++) {
        L = l[perm[i]];
        R = r[perm[i]] + 1;
        reverse(B.begin()+L, B.begin()+R);
    }
    do {
        cpy = vector<int>(A);
        for(int i=0 ; i<perm.size() ; i++) {
            L = l[perm[i]];
            R = r[perm[i]] + 1;
            reverse(cpy.begin()+L, cpy.begin()+R);
        }
        if(cpy == B)
            P++;
        Q++;
    }while(next_permutation(perm.begin(), perm.end()));
    gcd = __gcd(P, Q);
    P /= gcd;
    Q /= gcd;
    return to_string(P) + '/' + to_string(Q);
}

int main() {
    int T, N, M, num;
    vector<int> A, l, r;
    cin >> T;
    while(T--) {
        cin >> N >> M;
        for(int i=0 ; i<N ; i++) {
            cin >> num;
            A.push_back(num);
        }
        while(M--) {
            cin >> num;
            l.push_back(num);
            cin >> num;
            r.push_back(num);
        }
        cout << beatsAndPieces(A, l, r) << endl;
        A.clear();
        l.clear();
        r.clear();
    }
    return 0;
}