// Problem Code: HEADBOB

#include <iostream>
#include <string>

using namespace std;

string tanuAndHeadBob(string s){
    for(char c : s){
        if(c == 'I')
            return "INDIAN";
        else if(c == 'Y')
            return "NOT INDIAN";
    }
    return "NOT SURE";
}

int main()
{
    int T, N;
    string s;
    cin >> T;
    for(int i=1 ; i<=T ; i++){
        cin >> N >> s;
        cout << tanuAndHeadBob(s) << endl;
    }
    return 0;
}