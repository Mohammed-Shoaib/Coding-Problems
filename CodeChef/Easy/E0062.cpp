// Problem Code: LUCKYSTR

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string littleElephantAndStrings(string S, vector<string> A) {
    if(S.length() >= 47)
        return "Good";
    for (int i = 0 ; i < A.size() ; i++)
        if (S.find(A[i]) != string::npos)
            return "Good";
    return "Bad";
}

int main() {
    int K, N;
    string S;
    vector<string> A;
    cin >> K >> N;
    while (K--) {
        cin >> S;
        A.push_back(S);
    }
    while (N--) {
        cin >> S;
        cout << littleElephantAndStrings(S, A) << endl;
    }
    return 0;
}