// Problem Code: DWNLD

#include <iostream>
#include <vector>

using namespace std;

int downloadFile(int K, vector<int> T, vector<int> D) {
    int i, min, cost;
    cost = 0;
    for(min=i=0 ; i<T.size() ; i++) {
        min += T[i];
        if(min > K) {
            T[i] = min - K;
            break;
        }
    }
    for(; i<T.size() ; i++)
        cost += T[i]*D[i];
    return cost;
}

int main() {
    int TC, N, K, num;
    vector<int> T, D;
    cin >> TC;
    while(TC--) {
        cin >> N >> K;
        for(int i=0 ; i<N ; i++) {
            cin >> num;
            T.push_back(num);
            cin >> num;
            D.push_back(num);
        }
        cout << downloadFile(K, T, D) << endl;
        T.clear();
        D.clear();
    }
    return 0;
}