// Problem Code: CHEFZOT

#include <iostream>
#include <vector>

using namespace std;

int chefAndSubarray(vector<int> A) {
    int maxLength, length;
    maxLength = length = 0;
    for(int i=0 ; i<A.size() ; i++) {
        (!A[i]) ? length = 0 : length++;
        if(length > maxLength)
                maxLength = length;
    }
    return maxLength;
}

int main() {
    int N, num;
    vector<int> A;
    cin >> N;
    for(int i=0 ; i<N ; i++) {
        cin >> num;
        A.push_back(num);
    }
    cout << chefAndSubarray(A);
    return 0;
}