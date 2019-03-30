#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int bridges(int N, vector<int> &X, vector<int> &T) {
    int max_count, count;
    priority_queue<int, vector<int>, greater<int> > pq;
    max_count = count = 0;
    for (int i = 0; i < N; i++) {
        while (!pq.empty() && pq.top() < X[i]) {
            pq.pop();
            count--;
        }
        count++;
        max_count = max(count, max_count);
        pq.push(X[i] + T[i]);
    }
    return max_count;
}

int main() {
    freopen("bridges.in", "r", stdin);
    freopen("output.out", "w", stdout);
    
    int t, k = 1;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> X(N), T(N);
        for (int i = 0; i < N; i++)
            cin >> X[i] >> T[i];
        cout << k << ". " << bridges(N, X, T) << endl;
        k++;
    }
    
    return 0;
}