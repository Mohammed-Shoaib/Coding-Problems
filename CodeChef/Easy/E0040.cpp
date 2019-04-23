// Problem Code: TAVISUAL

#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int ballAndCups(int N, int C, vector<pair<int, int>> &queries) {
    int L, R;
    for(int i=0 ; i<queries.size() ; i++){
        L = queries[i].first;
        R = queries[i].second;
        if(C >= L && C <= R)
            C = R - C + L;
    }
    return C;
}

int main() {
    int T, N, C, Q, L, R;
    vector<pair<int, int>> queries;
    cin >> T;
    while(T--){
        cin >> N >> C >> Q;
        for(int i=0 ; i<Q ; i++){
            cin >> L >> R;
            queries.push_back(make_pair(L, R));
        }
        cout << ballAndCups(N, C, queries) << endl;
        queries.clear();
    }
    return 0;
}