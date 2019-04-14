#include <iostream>
#include <cstdio>

using namespace std;

bool is_leap(long long year) {
    return (year % 400 == 0 || year % 4 == 0 && year % 100 != 0);
}

long long count_leap(long long year) {
    return year / 400 - year / 100 + year / 4;
}

string leap(long long S, long long E) {
    if (!is_leap(S))
        return "Not a leap year!";
    else
        return to_string(count_leap(E) - count_leap(S));
}

int main() {
    freopen("leap.in", "r", stdin);
    freopen("output.out", "w", stdout);

    int T, k = 1;
    cin >> T;
    while (T--) {
        long long S, E;
        cin >> S >> E;
        cout << k << ". " << leap(S, E) << endl;
        k++;
    }

    return 0;
}