#include <iostream>
#include <cstdio>
#include <iomanip>
#include <cmath>
#include <utility>
#include <vector>

using namespace std;

bool in_range(pair<int, int> p1, pair<int, int> p2, int r) {
    long long x, y;
    double dist;
    x = (p1.first - p2.first) * (p1.first - p2.first);
    y = (p1.second - p2.second) * (p1.second - p2.second);
    dist = sqrt(x + y);
    return (dist <= r) ? true : false;
}

double dance(int K, vector<int> &E, vector<int> &R, vector< pair<int, int> > &D, vector< pair<int, int> > &S) {
    double energy = 0;
    for (int i = 0; i < D.size(); i++)
        for (int j = 0; j < S.size(); j++)
            if (in_range(D[i], S[j], R[j])) {
                energy += K * E[i];
                break;
            }
    return energy;
}

int main() {
    freopen("dance.in", "r", stdin);
    freopen("output.out", "w", stdout);
    cout << setprecision(2) << fixed;
    
    int N, k;
    k = 1;
    cin >> N;
    while (N--) {
        int D, S, K;
        cin >> D >> S >> K;
        vector<int> E(D), R(S), count(D);
        vector< pair<int, int> > dancers(D), sensors(S);
        for (int i = 0; i < D; i++)
            cin >> dancers[i].first >> dancers[i].second >> E[i];
        for (int i = 0; i < S; i++)
            cin >> sensors[i].first >> sensors[i].second >> R[i];
        cout << k << ". " << dance(K, E, R, dancers, sensors) << endl;
        k++;
    }
    
    return 0;
}