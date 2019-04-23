// Problem Code: RAINBOWA

#include <iostream>
#include <vector>

using namespace std;

string rainbowArray(vector<int> A) {
    int last,len;
    last = A[0];
    len = (A.size()+1)/2;
    if(A[0] != 1 || A[len-1] != 7)
        return "no";
    for(int i=0, j=A.size()-1 ; i<len ; last = A[i++], j--)
        if( (A[i] != A[j]) || (A[i] != last && A[i] != last+1) )
            return "no";
    return "yes";
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
        cout << rainbowArray(A) << endl;
        A.clear();
    }
    return 0;
}