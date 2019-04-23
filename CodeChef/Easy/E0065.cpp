// Problem Code: NOTATRI

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int numberOfTriples(vector<int> L) {
    int bound, triples = 0;
    sort(L.begin(), L.end());
    for (int i = 0 ; i < L.size() - 2; i++)
        for (int k, j = i + 1 ; j < L.size() - 1 ; j++) {
            bound = L[i] + L[j];
            k = j + 1;
            triples += L.size() - distance(L.begin(), upper_bound(L.begin() + k, L.end(), bound));
        }
    return triples;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    while (cin >> n, n > 0) {
        vector<int> L(n);
        for (int i = 0 ; i < n ; i++)
            cin >> L[i];
        cout << numberOfTriples(L) << endl;
    }
    return 0;
}