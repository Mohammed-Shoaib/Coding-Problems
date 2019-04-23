// Problem Code: DIVIDING

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

string dividingStamps(vector<int> C){
    int sum = accumulate(C.begin(), C.end(), 0);
    int divSum = C.size()*(C.size()+1)/2;
    return (divSum == sum) ? "YES" : "NO";
}

int main()
{
    int N, num;
    vector<int> C;
    cin >> N;
    for(int i=0 ; i<N ; i++){
        cin >> num;
        C.push_back(num);
    }
    cout << dividingStamps(C);
    return 0;
}