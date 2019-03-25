#include <iostream>
#include <cstdio>

using namespace std;

int pisano(int N) {
    if (N == 1)
        return 1;
    int f0, f1, f, period;
    f0 = 0;
    f1 = 1;
    period = 3;
    while(true) {
        f = (f0 + f1) % N;
        if (f1 == 0 && f == 1)
            break;
        f0 = f1;
        f1 = f;
        period++;
    }
    return period - 2;
}

int main() {
    freopen("pisano.in", "r", stdin);
    freopen("output.out", "w", stdout);
    int N;
    while (cin >> N && N)
        cout << pisano(N) << endl;
    return 0;
}