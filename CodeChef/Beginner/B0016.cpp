// Problem Code: REMISS

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int T, A, B;
    cin >> T;
    for(int i=1 ; i<=T ; i++){
        cin >> A >> B;
        cout << max(A,B) << " " << A+B << endl;
    }
    return 0;
}