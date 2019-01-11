// Problem Code: ANUARM

#include <iostream>
#include <vector>
#include <cmath>
#include <utility>
#include <algorithm>

using namespace std;

vector<int> theArmy(int N, vector<int> M) {
    pair<int, int> mnmx;
    vector<int> soldiers(N);
    mnmx.first = *min_element(M.begin(), M.end());
    mnmx.second = *max_element(M.begin(), M.end());
    for (int j=0 ; j < N ; j++)
        soldiers[j] = max(abs(mnmx.first - j), abs(mnmx.second - j));
    return soldiers;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        vector<int> results, rounds(M);
        for (int i=0 ; i < M ; i++)
            cin >> rounds[i];
        results = theArmy(N, rounds);
        for (int i=0 ; i < N ; i++)
            cout << results[i] << " ";
        cout << endl;
    }
    return 0;
}