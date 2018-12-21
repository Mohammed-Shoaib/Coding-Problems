// Problem Code: CHEFA

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long chefAndStones(vector<int> A) {
    long stones = 0;
    sort(A.rbegin(), A.rend());
    for(int i=0 ; i<A.size() ; i+=2)
        stones += A[i];
    return stones;
}

int main() {
    int T, N, num;
    vector<int> A;
    cin >> T;
    while(T--) {
        cin >> N;
        for(int i=0 ; i<N ; i++) {
            cin >> num;
            A.push_back(num);
        }
        cout << chefAndStones(A) << endl;
        A.clear();
    }
    return 0;
}