// Problem Code: ICPC16B

#include <iostream>
#include <vector>

using namespace std;

string beautifulArrays(vector<int> a) {
    if(a.size() == 1)
        return "yes";
    int zeros, posOnes, negOnes, other;
    zeros = posOnes = negOnes = other = 0;
    for(int i=0 ; i<a.size() ; i++)
        switch(a[i]) {
            case 0:
                zeros++;
                break;
            case 1:
                posOnes++;
                break;
            case -1:
                negOnes++;
                break;
            default:
                other++;
        }
    if( (other>1) || (other == 1 && negOnes > 0) || (negOnes > 1 && posOnes == 0) )
       return "no";
    else
        return "yes";
}

int main() {
    int T, n, num;
    vector<int> a;
    cin >> T;
    while(T--) {
        cin >> n;
        for(int i=0 ; i<n ; i++) {
            cin >> num;
            a.push_back(num);
        }
        cout << beautifulArrays(a) << endl;
        a.clear();
    }
    return 0;
}