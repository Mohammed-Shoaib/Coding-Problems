// Problem Code: ALEXNUMB

#include <iostream>
#include <vector>

using namespace std;

long magicPairs(vector<int> &a){
    long N = a.size();
    return N*(N-1)/2;
}

int main(){
    int T, n, num;
    vector<int> a;
    cin >> T;
    while(T--){
        cin >> n;
        for(int i=0 ; i<n ; i++){
            cin >> num;
            a.push_back(num);
        }
        cout << magicPairs(a) << endl;
        a.clear();
    }
    return 0;
}