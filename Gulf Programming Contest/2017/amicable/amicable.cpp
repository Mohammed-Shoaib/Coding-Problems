#include <iostream>
#include <cstdio>

using namespace std;

bool amicable(int a, int b) {
    int sum_a, sum_b;
    sum_a = sum_b = 0;
    for (int i = 1; i < a; i++)
        if (a % i == 0)
            sum_a += i;
    for (int i = 1; i < b; i++)
        if (b % i == 0)
            sum_b += i;
    return (sum_a == b && sum_b == a) ? true : false;
}

int main() {
    freopen("amicable.in", "r", stdin);
    freopen("output.out", "w", stdout);
    int nP;
    cin >> nP;
    while (nP--) {
        int a, b;
        cin >> a >> b;
        cout << a << " " << b << " are ";
        if (!amicable(a, b))
            cout << "not ";
        cout << "amicable numbers" << endl;
    }
    return 0;
}