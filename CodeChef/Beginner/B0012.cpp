// Problem Code: FLOW004

#include <iostream>
#include <cmath>

using namespace std;

int firstAndLastDigit(int N){
    int first = N / pow(10, floor(log(N)/log(10)));
    int last = N % 10;
    return first + last;
}

int main()
{
    int T, N;
    cin >> T;
    for(int i=1 ; i<=T ; i++){
        cin >> N;
        cout << firstAndLastDigit(N) << endl;
    }
    return 0;
}