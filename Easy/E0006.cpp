/*
Problem Statement: https://www.hackerrank.com/challenges/plus-minus/problem
*/

#include <iostream>
#include <vector>

using namespace std;

void plusMinus(vector<int> arr) {
    vector<double> count{0,0,0};
    for(int num: arr){
        if(num > 0)
            count[0]++;
        else if(num < 0)
            count[1]++;
        else
            count[2]++;
    }
    for(int i=0 ; i<count.size() ; i++){
        count[i] /= arr.size();
        printf("%0.6f\n",count[i]);
    }
}

int main()
{
    int len, num;
    cin>>len;
    vector<int> arr;
    for(int i=0 ; i<len ; i++){
        cin>>num;
        arr.push_back(num);
    }
    plusMinus(arr);
    return 0;
}