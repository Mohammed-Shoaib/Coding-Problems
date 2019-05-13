// Problem Code: CHEFSTUD

#include <iostream>
#include <string>

using namespace std;

int chefAndHisStudents(string s) {
    int punished = 0;
    for(int i=0 ; i<s.length()-1 ; i++)
        if(s[i] == '<' && s[i+1] == '>')
            punished++;
    return punished;
}

int main(){
    int T;
    string s;
    cin >> T;
    while(T--) {
        cin >> s;
        cout << chefAndHisStudents(s) << endl;
    }
    return 0;
}