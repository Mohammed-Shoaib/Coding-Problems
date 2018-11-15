// Problem Code: FLOW009

#include <iostream>
#include <stdio.h>

using namespace std;

double totalExpenses(int quantity, int price){
    double expense = quantity * price;
    if(quantity > 1000)
        expense -= expense/10;
    return expense;
}

int main()
{
    int T, quantity, price;
    cin >> T;
    for(int i=1 ; i<=T ; i++){
        cin >> quantity >> price;
        printf("%lf\n", totalExpenses(quantity, price));
    }
    return 0;
}