// Problem Code: COINS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int maxN = 10000000;
vector<long> bgc(maxN+1);

long exchange(long n){
    long c1, c2, c3;
    c1 = n/2;
    c2 = n/3;
    c3 = n/4;
    c1 = (c1 <= maxN) ? max(c1, bgc[c1]) : max(c1, exchange(c1));
    c2 = (c2 <= maxN) ? max(c2, bgc[c2]) : max(c2, exchange(c2));
    c3 = (c3 <= maxN) ? max(c3, bgc[c3]) : max(c3, exchange(c3));
    return c1 + c2 + c3;
}

int main()
{
    long n;
    for(long i=0 ; i<bgc.size() ; i++)
        bgc[i] = max(i, bgc[i/2] + bgc[i/3] + bgc[i/4]);
    while(cin >> n){
        if(n <= maxN)
            cout << bgc[n] << endl;
        else
            cout << max(n, exchange(n)) << endl;
    }
    return 0;
}