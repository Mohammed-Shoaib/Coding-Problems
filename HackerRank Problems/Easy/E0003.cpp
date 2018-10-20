/*
Problem Statement: https://www.hackerrank.com/challenges/compare-the-triplets/problem
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> compareTriplets(vector<int> a, vector<int> b) {
    vector<int> scores{0,0};
    for(int i=0 ; i<a.size() ; i++){
        if(a[i] > b[i])
            scores[0]++;
        else if(a[i] < b[i])
            scores[1]++;
    }
    return scores;
}

int main()
{
    vector<int> a,b;
    int num;
    for(int i=0 ; i<3 ; i++){
        cin>>num;
        a.push_back(num);
    }
    for(int i=0 ; i<3 ; i++){
        cin>>num;
        b.push_back(num);
    }
    vector<int> scores = compareTriplets(a,b);
    for(int i=0 ; i<scores.size() ; i++)
        cout<<scores[i]<<" ";
    return 0;
}