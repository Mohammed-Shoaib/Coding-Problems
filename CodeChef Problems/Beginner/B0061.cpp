// Problem Code: ALTARAY

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> alternatingSubarray(vector<int> A) {
    vector<int> x(A.size(), 1);
    for(int i=A.size()-2 ; i>=0 ; i--)
        if(signbit(A[i]) != signbit(A[i+1]))
            x[i] += x[i+1];
    return x;
}

int main() {
    int T, N, num;
    vector<int> A, x;
    cin >> T;
    while(T--) {
        cin >> N;
        for(int i=0 ; i<N ; i++) {
            cin >> num;
            A.push_back(num);
        }
        x = alternatingSubarray(A);
        for(int i=0 ; i<x.size() ; i++)
            cout << x[i] << " ";
        cout << endl;
        A.clear();
    }
    return 0;
}