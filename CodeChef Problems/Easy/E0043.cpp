// Problem Code: LUCKY5

#include <iostream>
#include <string>

using namespace std;

int luckyLong(string &N) {
    int count = 0;
    for(char &c : N)
        if(c != '4' && c != '7')
            count++;
    return count;
}

int main() {
    int T;
    string N;
    cin >> T;
    while(T--) {
        cin >> N;
        cout << luckyLong(N) << endl;
    }
    return 0;
}