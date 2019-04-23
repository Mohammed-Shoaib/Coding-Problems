// Problem Code: TACHSTCK

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int chopsticks(int D, vector<int> L){
    int pairs = 0;
    sort(L.begin(), L.end());
    for(int i=1 ; i<L.size() ; i++)
        if(L[i] - L[i-1] <= D){
            pairs++;
            i++;
        }
    return pairs;
}

int main(){
    int N, D, num;
    vector<int> L;
    cin >> N >> D;
    for(int i=0 ; i<N ; i++){
        cin >> num;
        L.push_back(num);
    }
    cout << chopsticks(D, L);
    return 0;
}