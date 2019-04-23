// Problem Code: SIMPSTAT

#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

double simpleStatistics(int K, vector<int> A) {
    sort(A.begin(), A.end());
    int sum = accumulate(A.begin()+K, A.end()-K, 0);
    double n = A.size() - 2*K;
    return sum/n;
}

int main() {
    int T, N, K, num;
    vector<int> A;
    cout << fixed << setprecision(6);
    cin >> T;
    while(T--) {
        cin >> N >> K;
        for(int i=0 ; i<N ; i++) {
            cin >> num;
            A.push_back(num);
        }
        cout << simpleStatistics(K, A) << endl;
        A.clear();
    }
    return 0;
}