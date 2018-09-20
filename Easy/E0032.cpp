/*
Problem Statement: https://www.hackerrank.com/challenges/fair-rations/problem
*/

#include <iostream>
#include <vector>

using namespace std;

int fairRations(vector<int> B) {
    int sum, count;
    sum = count = 0;
    for(int i=0 ; i<B.size() ; i++){
        sum += B[i];
        if(sum&1)
            count += 2;
    }
    if(sum&1)
        return -1;
    else
        return count;
}

int main()
{
    int N, num;
    vector<int> B;
    cin>>N;
    for(int i=0 ; i<N ; i++){
        cin>>num;
        B.push_back(num);
    }
    int count = fairRations(B);
    if(count != -1)
        cout<<count<<endl;
    else
        cout<<"NO"<<endl;
	return 0;
}