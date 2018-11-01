// Problem Code: FLOW017

#include <iostream>
#include <set>

using namespace std;

int secondLargest(int A, int B, int C){
    set<int> numbers({A, B, C});
    return *next(numbers.begin(), 1);
}

int main()
{
    int T, A, B, C;
    cin >> T;
    for(int i=1 ; i<=T ; i++){
        cin >> A >> B >> C;
        cout << secondLargest(A, B, C) << endl;
    }
    return 0;
}