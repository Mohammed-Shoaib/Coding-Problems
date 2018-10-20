/*
Problem Statement: https://www.hackerrank.com/challenges/designer-pdf-viewer/problem
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int designerPdfViewer(vector<int> h, string word) {
    for(char &c : word)
        c -= 97;
    set<int> letters(word.begin(),word.end());
    vector<int> arr;
    for(auto itr=letters.begin() ; itr != letters.end() ; itr++)
        arr.push_back(h[*itr]);
    int max = *max_element(arr.begin(),arr.end());
    return max*word.length();
}

int main()
{
    int num;
    string word;
    vector<int> h;
    for(int i=1 ; i<=26 ; i++){
        cin>>num;
        h.push_back(num);
    }
    cin.ignore();
    getline(cin,word);
    cout<<designerPdfViewer(h,word);
    return 0;
}