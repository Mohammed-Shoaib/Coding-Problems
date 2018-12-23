// Problem Code: CUTPIZ

#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

int cuttingPizza(vector<int> a) {
    int gcd, cuts;
    sort(a.begin(), a.end());
    gcd = 360;
    if(a[0] != 0)
        transform(a.begin(), a.end(), a.begin(), bind2nd(minus<int>(), a[0]));
    for(int i=0 ; i<a.size() ; i++)
        gcd = __gcd(a[i], gcd);
    cuts = 360/gcd - a.size();
    return cuts;
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
        cout << cuttingPizza(a) << endl;
        a.clear();
    }
    return 0;
}