// Problem Code: LEPERMUT

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string permutation(vector<int> A){
    for(int i=0 ; i<(int)A.size()-2 ; i++)
        for(int j=i+2 ; j<A.size() ; j++)
            if(A[i] > A[j])
                return "NO";
    return "YES";
}

int main()
{
    int T, N, num;
    vector<int> A;
    cin >> T;
    while(T--){
        cin >> N;
        for(int i=0 ; i<N ; i++){
            cin >> num;
            A.push_back(num);
        }
        cout << permutation(A) << endl;
        A.clear();
    }
    return 0;
}