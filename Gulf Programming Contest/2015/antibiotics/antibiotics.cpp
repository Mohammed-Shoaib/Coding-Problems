#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <unordered_set>
#include <queue>
#include <algorithm>

using namespace std;

map<int, int> antibiotics(int C, vector<int> &P, vector<int> &S, vector<int> &E) {
    map<int, int> overlaps;
    unordered_set<int> patients(P.begin(), P.end());
    
    for (auto patient: patients) {
        int max_count, count;
        max_count = count = 0;
        vector< pair<int, int> > times;
        priority_queue<int, vector<int>, greater<int> > pq;
        
        for (int i = 0; i < C; i++)
            if (patient == P[i])
                times.push_back({S[i], E[i]});
        sort(times.begin(), times.end());

        for (int i = 0; i < times.size(); i++) {
            while (!pq.empty() && pq.top() < times[i].first) {
                pq.pop();
                count--;
            }
            pq.push(times[i].second);
            count++;
            max_count = max(count, max_count);
        }

        if (max_count > 1)
            overlaps[patient] = max_count;
    }
    
    return overlaps;
}

int main() {
    freopen("antibiotics.in", "r", stdin);
    freopen("output.out", "w", stdout);
    
    int N;
    cin >> N;
    while (N--) {
        int C;
        cin >> C;
        map<int, int> overlaps;
        vector<int> P(C), S(C), E(C);
        for (int i = 0; i < C; i++)
            cin >> P[i] >> S[i] >> E[i];
        overlaps = antibiotics(C, P, S, E);
        if (overlaps.size() == 0)
            cout << "All Clear" << endl;
        else
            for (auto overlap: overlaps)
                cout << overlap.first << " " << overlap.second << endl;
        if (N > 0)
            cout << endl;
    }

    return 0;
}