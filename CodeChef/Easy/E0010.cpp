// Problem Code: MIME2

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

string mediaType(unordered_map<string, string> &table, string name){
    string token;
    unordered_map<string, string>::iterator it;
    stringstream ss(string(name.rbegin(), name.rend()));
    getline(ss, token, '.');
    if(ss.str() == token)
        return "unknown";
    reverse(token.begin(), token.end());
    it = table.find(token);
    return (it != table.end()) ? it->second : "unknown";
}

int main()
{
    int N, Q;
    string extension, media, name;
    unordered_map<string, string> table;
    cin >> N >> Q;
    cin.ignore();
    for(int i=1 ; i<=N ; i++){
        cin >> extension >> media;
        table[extension] = media;
    }
    for(int i=1 ; i<=Q ; i++){
        cin >> name;
        cout << mediaType(table, name) << endl;
    }
    return 0;
}