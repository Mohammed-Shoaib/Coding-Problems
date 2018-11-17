// Problem Code: CHEFSQ

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string chefAndHisSequence(vector<int> N, vector<int> F) {
    int i, j;
    for(i=0, j=0 ; i<N.size() && j<F.size() ; i++)
        if(N[i] == F[j])
            j++;
    return (j == F.size()) ? "Yes" : "No";
}

int main() {
    int T, N, F, num;
    vector<int> A, B;
    cin >> T;
    while(T--) {
        cin >> N;
        for(int i=0 ; i<N ; i++) {
            cin >> num;
            A.push_back(num);
        }
        cin >> F;
        for(int i=0 ; i<F ; i++) {
            cin >> num;
            B.push_back(num);
        }
        cout << chefAndHisSequence(A, B) << endl;
        A.clear();
        B.clear();
    }
    return 0;
}