// Problem Code: CCOOK

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string chefAndCookOff(vector<int> A) {
    int solved = count(A.begin(), A.end(), 1);
    switch(solved) {
        case 0:
            return "Beginner";
        case 1:
            return "Junior Developer";
        case 2:
            return "Middle Developer";
        case 3:
            return "Senior Developer";
        case 4:
            return "Hacker";
        default:
            return "Jeff Dean";
    }
}

int main() {
    int N, num;
    vector<int> A;
    cin >> N;
    while(N--) {
        for(int i=0 ; i<5 ; i++) {
            cin >> num;
            A.push_back(num);
        }
        cout << chefAndCookOff(A) << endl;
        A.clear();
    }
    return 0;
}