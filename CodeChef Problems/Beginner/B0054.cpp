// Problem Code: RRJOKE

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

void forgottenLanguage(vector<string> N, unordered_set<string> K) {
    for(int i=0 ; i<N.size() ; i++) {
        if(K.find(N[i]) != K.end())
            cout << "YES ";
        else
            cout << "NO ";
    }
    cout << endl;
}

int main() {
    int T, N, K, L;
    string s;
    vector<string> dictionary;
    unordered_set<string> modern;
    cin >> T;
    while(T--) {
        cin >> N >> K;
        for(int i=0 ; i<N ; i++) {
            cin >> s;
            dictionary.push_back(s);
        }
        for(int i=0 ; i<K ; i++) {
            cin >> L;
            for(int j=0 ; j<L ; j++) {
                cin >> s;
                modern.insert(s);
            }
        }
        forgottenLanguage(dictionary, modern);
        dictionary.clear();
        modern.clear();
    }
    return 0;
}