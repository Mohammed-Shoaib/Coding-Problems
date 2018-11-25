// Problem Code: TOTR

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

string touristTranslation(string S, unordered_map<char, char> &translation){
    char c;
    for(int i=0 ; i<S.length() ; i++){
        c = S[i];
        S[i] = translation[tolower(S[i])];
        if(isupper(c))
            S[i] = toupper(S[i]);
    }
    return S;
}

int main(){
    int T;
    string M, S;
    unordered_map<char, char> translation({{'_', ' '}, {'.', '.'}, {',', ','}, {'!', '!'}, {'?', '?'}});
    cin >> T >> M;
    for(int i=0 ; i<M.length() ; i++)
        translation['a' + i] = M[i];
    while(T--){
        cin >> S;
        cout << touristTranslation(S, translation) << endl;
    }
    return 0;
}