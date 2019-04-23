// Problem Code: CHOPRT

#include <iostream>

using namespace std;

char chefAndOperators(int A, int B){
    if(A < B)
        return '<';
    else if(A > B)
        return '>';
    else
        return '=';
}

int main()
{
    int T, A, B;
    cin >> T;
    for(int i=1 ; i<=T ; i++){
        cin >> A >> B;
        cout << chefAndOperators(A, B) << endl;
    }
    return 0;
}