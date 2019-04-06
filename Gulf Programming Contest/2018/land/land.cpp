#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector<long long> land(int n, vector<int> &X, vector<int> &Y) {
    int size = 3;
    vector<long long> SX(size), SY(size), P(size);
    for (int i = 1; i <= n; i++) {
        SX[i % size] += X[i];
        SY[i % size] += Y[i];
    }
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            P[(i + j) % 3] += SX[i] * SY[j];
    return P;
}

int main() {
    freopen("land.in", "r", stdin);
    freopen("output.out", "w", stdout);
    
    int n;
    while (cin >> n && n) {
        vector<long long> P;
        vector<int> X(n + 1), Y(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> X[i];
        for (int i = 1; i <= n; i++)
            cin >> Y[i];
        P = land(n, X, Y);
        cout << P[2] << " " << P[1] << " " << P[0] << endl;
    }
    
    return 0;
}