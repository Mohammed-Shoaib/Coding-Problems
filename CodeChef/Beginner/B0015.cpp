// Problem Code: FSQRT

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int T, N, root;
    cin >> T;
    for(int i=1 ; i<=T ; i++){
        cin >> N;
        root = sqrt(N);
        cout << root << endl;
    }
    return 0;
}