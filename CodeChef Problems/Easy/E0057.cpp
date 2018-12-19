// Problem Code: MFREQ

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> Left, Right;

void preprocess(vector<int> A) {
    Left = vector<int>(A.size());
    Right = vector<int>(A.size());
    Left[0] = 0;
    Right[A.size()-1] = A.size()-1;
    for(int i=1 ; i<A.size() ; i++)
        Left[i] = (A[i] == A[i-1]) ? Left[i-1] : i;
    for(int i=A.size()-2 ; i>=0 ; i--)
        Right[i] = (A[i] == A[i+1]) ? Right[i+1] : i;
}

int mostFrequentElement(int L, int R, int k, vector<int> &A) {
    int mid, freq;
    mid = (L + R) / 2;
    freq = min(Right[mid], R) - max(Left[mid], L) + 1;
    return (freq < k) ? -1 : A[mid];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M, L, R, k, num;
    vector<int> A;
    cin >> N >> M;
    for(int i=0 ; i<N ; i++) {
        cin >> num;
        A.push_back(num);
    }
    preprocess(A);
    while(M--) {
        cin >> L >> R >> k;
        cout << mostFrequentElement(L-1, R-1, k, A) << endl;
    }
    return 0;
}