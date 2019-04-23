// Problem Code: AMR15A

#include <iostream>
#include <vector>

using namespace std;

string mahasena(vector<int> A){
    int lucky, unlucky;
    lucky = unlucky = 0;
    for(int i=0 ; i<A.size() ; i++)
        (A[i] & 1) ? unlucky++ : lucky++;
    return (lucky > unlucky) ? "READY FOR BATTLE" : "NOT READY";
}

int main()
{
    int N, num;
    vector<int> A;
    cin >> N;
    for(int i=0 ; i<N ; i++){
        cin >> num;
        A.push_back(num);
    }
    cout << mahasena(A);
    return 0;
}