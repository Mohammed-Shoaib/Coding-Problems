// Problem Code: PLAYFIT

#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

string fitToPlay(vector<int> g) {
    int min, diff;
    min = g[0];
    diff = numeric_limits<int>::min();
    for (int i = 1 ; i < g.size() ; i++) {
        if (diff < g[i] - min)
            diff = g[i] - min;
        if (min > g[i])
            min = g[i];
    }
    return (diff <= 0) ? "UNFIT" : to_string(diff);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T, N, num;
    vector<int> g;
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 0 ; i < N ; i++) {
            cin >> num;
            g.push_back(num);
        }
        cout << fitToPlay(g) << endl;
        g.clear();
    }
    return 0;
}