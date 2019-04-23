// Problem Code: CONFLIP

#include <iostream>

using namespace std;

int main()
{
    int T, G, I, N, Q, count;
    cin >> T;
    for(int i=1 ; i<=T ; i++){
        cin >> G;
        for(int j=1 ; j<=G ; j++){
            cin >> I >> N >> Q;
            if(N&1)
                count = (I == Q) ? N/2 : N/2 + 1;
            else
                count = N/2;
            cout << count << endl;
        }
    }
    return 0;
}