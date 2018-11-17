// Problem Code: MOVIEWKN

#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int movieWeekend(vector<int> L, vector<int> R) {
    int index, prod, maxR, maxProd;
    maxR = maxProd = numeric_limits<int>::min();
    for(int i=0 ; i<L.size() ; i++) {
        prod = L[i]*R[i];
        if(maxProd < prod) {
            index = i + 1;
            maxProd = L[i]*R[i];
            maxR = R[i];
        }
        else if(prod == maxProd && maxR < R[i]) {
            index = i + 1;
            maxR = R[i];
        }
    }
    return index;
}

int main() {
    int T, n, num;
    vector<int> L, R;
    cin >> T;
    while(T--) {
        cin >> n;
        for(int i=0 ; i<n ; i++) {
            cin >> num;
            L.push_back(num);
        }
        for(int i=0 ; i<n ; i++) {
            cin >> num;
            R.push_back(num);
        }
        cout << movieWeekend(L, R) << endl;
        L.clear();
        R.clear();
    }
    return 0;
}