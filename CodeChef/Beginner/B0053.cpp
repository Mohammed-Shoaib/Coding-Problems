// Problem Code: KTTABLE

#include <iostream>
#include <vector>

using namespace std;

int kitchenTimetable(vector<int> A, vector<int> B) {
    int count = (B[0] <= A[0]) ? 1 : 0;
    for(int i=1 ; i<A.size() ; i++)
        if(B[i] <= A[i] - A[i-1])
            count++;
    return count;
}

int main() {
    int T, N, num;
    vector<int> A, B;
    cin >> T;
    while(T--) {
        cin >> N;
        for(int i=0 ; i<N ; i++) {
            cin >> num;
            A.push_back(num);
        }
        for(int j=0 ; j<N ; j++) {
            cin >> num;
            B.push_back(num);
        }
        cout << kitchenTimetable(A, B) << endl;
        A.clear();
        B.clear();
    }
    return 0;
}