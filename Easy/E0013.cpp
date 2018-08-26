/*
Problem Statement: https://www.hackerrank.com/challenges/bon-appetit/problem
*/

#include <iostream>
#include <vector>

using namespace std;

void bonAppetit(vector<int> bill, int k, int b) {
    int bCharged,bActual;
    bCharged = b;
    bActual = 0;
    for(int i=0 ; i<bill.size() ; i++){
        if(i == k)
            continue;
        bActual += bill[i];
    }
    bActual /= 2;
    if(bCharged-bActual)
        cout<<bCharged - bActual<<endl;
    else
        cout<<"Bon Appetit"<<endl;
}

int main()
{
    int n,k,b,num;
    vector<int> bill;
    cin>>n>>k;
    for(int i=0 ; i<n ; i++){
        cin>>num;
        bill.push_back(num);
    }
    cin>>b;
    bonAppetit(bill,k,b);
    return 0;
}