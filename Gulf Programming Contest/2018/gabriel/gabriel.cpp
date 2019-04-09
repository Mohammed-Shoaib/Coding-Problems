#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <utility>

using namespace std;

double euclidean_distance(pair<int, int> &p1, pair<double, double> &p2) {
    double x, y;
    x = (p2.first - p1.first) * (p2.first - p1.first);
    y = (p2.second - p1.second) * (p2.second - p1.second);
    return sqrt(x + y);
}

bool neighbor(int i, int j, vector< pair<int, int> > &pos) {
    double R;
    pair<double, double> C;
    C.first = (pos[i].first + pos[j].first) / 2.0;
    C.second = (pos[i].second + pos[j].second) / 2.0;
    R = euclidean_distance(pos[i], C);
    for (int k = 1; k < pos.size(); k++)
        if(k != i && k != j && euclidean_distance(pos[k], C) < R)
            return false;
    return true;
}

vector< vector<int> > gabriel(int Z, vector<int> &P, vector< pair<int, int> > &pos) {
    vector< vector<int> > adj(Z + 1);
    for (int i = 1; i <= Z - 1; i++)
        for (int j = i + 1; j <= Z; j++)
            if (neighbor(i, j, pos)) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
    return adj;
}

int main() {
    freopen("gabriel.in", "r", stdin);
    freopen("output.out", "w", stdout);
    
    int X;
    cin >> X;
    while (X--) {
        int Y, Z;
        cin >> Y >> Z;
        vector<int> P(Z + 1);
        vector< pair<int, int> > pos(Z + 1);
        vector< vector<int> > adj;
        for (int i = 1; i <= Z; i++)
            cin >> P[i] >> pos[i].first >> pos[i].second;
        adj = gabriel(Z, P, pos);
        cout << Y << endl;
        for (int i = 1; i <= Z; i++) {
            cout << i;
            for (int j = 0; j < adj[i].size(); j++)
                cout << " " << adj[i][j];
            cout << endl;
        }
    }

    return 0;
}