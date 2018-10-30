// Problem Code: JOHNY

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int uncleJohny(int K, vector<int> A){
    K = A[K-1];
    sort(A.begin(), A.end());
    return distance(A.begin(), find(A.begin(), A.end(), K)) + 1;
}

int main()
{
    int T, N, K, num;
    vector<int> A;
    cin >> T;
    for(int i=1 ; i<=T ; i++){
        cin >> N;
        for(int i=0 ; i<N ; i++){
            cin >> num;
            A.push_back(num);
        }
        cin >> K;
        cout << uncleJohny(K, A) << endl;
        A.clear();
    }
    return 0;
}