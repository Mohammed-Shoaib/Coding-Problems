// Problem Code: FLOW015

#include <iostream>
#include <vector>

using namespace std;

string gregorianCalendar(int Y) {
    int P;
    vector<string> d1({"monday","tuesday","wednesday","thursday","friday","saturday","sunday"});
    vector<string> d2({"saturday","friday","thursday","wednesday","tuesday","monday","sunday"});
    P = (Y >= 2001) ? (Y - 2001) : (2000 - Y);
    P = (P + P/4 - P/100 + P/400) % 7;
    return (Y >= 2001) ? d1[P] : d2[P];
}

int main() {
    int T, Y;
    cin >> T;
    while(T--) {
        cin >> Y;
        cout << gregorianCalendar(Y) << endl;
    }
    return 0;
}