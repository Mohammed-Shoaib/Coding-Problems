// Problem Code: NAME1

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string nameReduction(string A, string B, vector<string> C){
    unordered_map<char, int> parent, children;
    for(int i=0 ; i<A.length() ; i++)
        parent[A[i]] += 1;
    for(int i=0 ; i<B.length() ; i++)
        parent[B[i]] += 1;
    for(int i=0 ; i<C.size() ; i++)
        for(int j=0 ; j<C[i].size() ; j++)
            children[C[i][j]] += 1;
    for(unordered_map<char, int>::iterator it=children.begin() ; it != children.end() ; it++)
        if(parent[it->first] < it->second)
            return "NO";
    return "YES";
}

int main()
{
    int T, N;
    string A, B, s;
    vector<string> C;
    cin >> T;
    cin.ignore();
    for(int i=1 ; i<=T ; i++){
        cin >> A >> B;
        cin >> N;
        cin.ignore();
        for(int j=1 ; j<=N ; j++){
            cin >> s;
            C.push_back(s);
        }
        cout << nameReduction(A, B, C) << endl;
        C.clear();
    }
    return 0;
}