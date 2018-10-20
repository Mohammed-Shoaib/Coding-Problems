/*
Problem Statement: https://www.hackerrank.com/challenges/breaking-best-and-worst-records/problem
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> breakingRecords(vector<int> scores) {
    vector<int> count{0,0};
    int minScore,maxScore;
    minScore = maxScore = scores[0];
    for(int i=1 ; i<scores.size() ; i++){
        if(maxScore < scores[i]){
            maxScore = scores[i];
            count[0]++;
        }else if(minScore > scores[i]){
            minScore = scores[i];
            count[1]++;
        }
    }
    return count;
}

int main()
{
    int n,num;
    vector<int> scores,count;
    cin>>n;
    for(int i=0 ; i<n ; i++){
        cin>>num;
        scores.push_back(num);
    }
    count = breakingRecords(scores);
    cout<<count[0]<<" "<<count[1]<<endl;
    return 0;
}